#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class AccountHolder {
public:
	string surname;
	string name;
	float rate;
	string reg;

	AccountHolder() {
		surname = "Pupkin";
		name = "Vasya";
		rate = 10;
		reg = "12.06.2021";
	};
	AccountHolder(string _surname, string _name, float _rate, string _reg) {
		surname = _surname;
		name = _name;
		rate = _rate;
		reg = _reg;
	};

	string answ()
	{
		return	"Прiзвище:\t" + surname + '\n' +
				"Iм'я:\t" + name + '\n' +
				"Кредитний рейтинг:\t" + to_string(rate) + '\n' +
				"Прiзвище:\t" + reg + '\n';
	}
};

class Operation {
public:
	bool type;
	string date;
	string process;

	Operation() {
		type = false;
		date = "12.06.2021";
		process = "Скасована";
	};
	Operation(bool _type, string _date, string _process) {
		type = _type;
		date = _date;
		process = _process;
	};
	string answ()
	{
		string temp = (type == true) ? "Прихiд" : "Витрата";
		return	"Тип:\t" + temp + '\n' + 
				"Дата:\t" + date + '\n' + 
				"Статус:\t" + process + '\n';
	}
};

class Account {
public:
	AccountHolder holder;
	string open;
	string close;
	float balance;
	Operation history[10];
	int count;

	Account() {
		holder = AccountHolder();
		open = "12.06.2021";
		close = "-";
		balance = 12701.12;
		count = 0;
	};
	Account(AccountHolder _holder, string _open, string _close, float _balance) {
		holder = _holder;
		open = _open;
		close = _close;
		balance = _balance;
		count = 0;
	};

	void NewOp(Operation op)
	{
		if (count < 10) {
			history[count] = op;
			count++;
		}
	}

	string answ()
	{
		return	holder.answ() + 
				"Дата вiдкриття:\t" + open + '\n' + 
				"Дата закриття:\t" + close + '\n' +
				"Залишок:\t" + to_string(balance) + '\n' +
				"Список:" + '\n' + this->hist();
	} 

	string hist()
	{
		string temp;
		for (int i = 0; i < count; i++)
		{
			temp += history[i].answ();
		}
		return temp;
	}
};
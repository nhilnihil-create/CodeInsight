#include<iostream>
#include<string>

using namespace std;

int const Month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string const Week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int main(){
	int month, day;

	while (cin >> month >> day){
		if ((month == 0) && (day == 0)) break;
		int today = day;
		month--;
		while (month){
			today += Month[month - 1];
			month--;
		}
		cout << Week[(today + 2) % 7] << endl;
	}

	return 0;
}
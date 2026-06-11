
#include<iostream>
#include<string>
#include<algorithm>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>

using namespace std;

int box[6] = {};
int a;

class Dice {
public:
	void s();
	void w();
	void n();
	void e();
};


void Dice::s() {
	a = box[0];
	box[0] = box[4];
	box[4] = box[5];
	box[5] = box[1];
	box[1] = a;
}
void Dice::w() {
	a = box[0];
	box[0] = box[2];
	box[2] = box[5];
	box[5] = box[3];
	box[3] = a;
}
void Dice::n() {
	a = box[0];
	box[0] = box[1];
	box[1] = box[5];
	box[5] = box[4];
	box[4] = a;
}
void Dice::e() {
	a = box[0];
	box[0] = box[3];
	box[3] = box[5];
	box[5] = box[2];
	box[2] = a;
}

int main() {
	int i;
	string str1,str2;
	Dice dice1;
	for (i = 0; i < 6; i++) {
		cin >> box[i];
	}
	getline(cin, str1);
	getline(cin, str2);

	for (i = 0;i<str2.length();i++) {
		if (str2[i] == 'S') {
			dice1.s();
		}
		else if (str2[i] == 'W') {
			dice1.w();
		}
		else if (str2[i] == 'N') {
			dice1.n();
		}
		else {
			dice1.e();
		}
	}
	std::cout << box[0] << endl;

	return 0;
}


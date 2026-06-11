#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	int s;
	int a;

	cin >> s;

	a = s % 10;

	if (a == 2 || a == 4 || a == 5 || a == 7 || a == 9) {
		cout << "hon" << "\n";
	}
	else if (a == 3) {
		cout << "bon" << "\n";
	}
	else {
		cout << "pon" << "\n";
	}

}
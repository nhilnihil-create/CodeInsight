#include<iostream>
#include<string>
using namespace std;
 
int main() {
	string S;
	cin >> S;
	if (S == "RRR") {
		cout << "3\n";
	}
	else if (S == "SSS") {
		cout << "0\n";
	}
	else if ((int)S.find("RR") >= 0) {
		cout << "2\n";
	}
	else {
		cout << "1\n";
	}
	return 0;
}
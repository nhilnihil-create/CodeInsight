/*
find integral(0, 600) x^2
*/

#include<iostream>
#include<fstream>
using namespace std;

int f(int x);
const int btm = 0, top = 600;

int main() {
	int d;

	while(cin >> d && d != EOF) {
		int itg = 0;
		for(int i = btm + d; i < top; i += d) { itg += f(i) * d; }

		cout << itg << endl;
	}
}

int f(int x) {
	return x * x;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	int a;
	int b;
	int c;

	cin >> a;
	cin >> b;
	cin >> c;

	int d;

	d = a;
	a = b;
	b = d;

	d = c;
	c = a;
	a = d;

	cout << a << " " << b << " " << c << "\n";

}
#include<iostream>
using namespace std;

int main() {
	int X;
	cin >> X;

	int A = X / 500;
	int B = X % 500 / 5;

	cout << A * 1000 + B * 5 << endl;
}
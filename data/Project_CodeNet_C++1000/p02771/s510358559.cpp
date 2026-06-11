#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int A;
	int B;
	int C;
	cin >> A >> B >> C;
	int a;
	int b;
	int c;
	a = A - B;
	b = A - C;
	c = B - C;
	if (A == B&&B == C) {
		cout << "No" << endl;
	}
	else {
		if (a == 0 || b == 0 || c == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
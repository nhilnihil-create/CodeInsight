#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int main() {
	long long a,b;
	cin >> a >> b;
	if (a ==  1 || b == 1) {
		cout << "1";
	}
	else {
		cout << (a * b + 1) / 2;
	}
}

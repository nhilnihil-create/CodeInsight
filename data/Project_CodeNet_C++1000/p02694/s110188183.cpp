#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	long long X;

	cin >> X;

	long long temp = 100, cnt = 1;
	while (1) {
		temp = temp + temp / 100;
		if (temp >= X) {
			cout << cnt << endl;
			return 0;
		}
		cnt++;
	}
	return 0;
}
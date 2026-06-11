#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
	char c[1001];
	int i, sum = 0;
	long long x;
	while (1) {
		cin >> c;
		if (c[0] == '0')break;
		for (i = 0; i < strlen(c); i++) {
			sum += c[i] - '0';
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
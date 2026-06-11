#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
	int a, b;
	cin >> a >> b;
	if (a % (2 * b + 1) == 0)cout << a / (2 * b + 1) << endl;
	else cout << a / (2 * b + 1) + 1 << endl;
	return 0;
}
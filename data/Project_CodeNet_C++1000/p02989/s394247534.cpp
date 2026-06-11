#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int lst[100010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	sort(lst, lst + n);
	if (n % 2 == 1) {
		if (lst[n / 2] == lst[n / 2 + 1]) {
			cout << 0 << endl;
		}
		else cout << 1 << endl;
	}
	else {
		cout << lst[n / 2] - lst[(n - 1) / 2] << endl;
	}
	return 0;
}
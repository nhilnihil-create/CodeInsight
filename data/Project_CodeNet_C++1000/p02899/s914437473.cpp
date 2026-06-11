#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int ans[100010];
int main() {
	int n,pos;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos;
		ans[pos-1] = i + 1;
	}
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << " ";
	}
	cout << ans[n-1] << endl;
	return 0;
}
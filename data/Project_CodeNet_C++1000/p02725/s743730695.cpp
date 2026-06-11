#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
int lst[200010];
int main() {
	int k;
	int n;
	int ans;
	cin >> k  >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	ans = -lst[n - 1] + lst[0] +k;
	for (int i = 0; i < n - 1; i++) {
		if (lst[i + 1] - lst[i] > ans)ans = lst[i + 1] - lst[i];
	}
	cout << k - ans << endl;
	return 0;
}
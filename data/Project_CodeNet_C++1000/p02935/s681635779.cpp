#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
double lst[100010];
int main() {
	int n,pos;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	sort(lst, lst + n);
	for (int i = 1; i < n; i++) {
		lst[i] = (lst[i] + lst[i - 1]) / 2;
	}
	cout << lst[n-1] << endl;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	if (n > k)n = n - (n/k)*k;
	cout << min(k-n, n) << endl;
	return 0;
}
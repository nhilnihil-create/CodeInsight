// ABC167Ddoubling.cpp
// doubling
//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
long long d[60][200000] = {};
int main()
{
	long long n, k;
	cin >> n >> k;
	vector<long long>a(n+1);
	for (long long i = 1; i <= n; i++) cin >> a.at(i);
	int dgt = 0;
	long long num = k;
	vector<int>bt;
	while (num > 0) {
		bt.push_back(num % 2);
		num = num / 2;
		dgt++;
	}
	for (int i = 1; i <= n; i++) {
		d[0][i] = a[i];
	}
	for (int i = 1; i < dgt; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j]=d[i-1][d[i-1][j]];
		}
	}
	ll ans = 1;
	for (int i = bt.size() - 1; i >= 0; i--) {
		if (bt.at(i) == 1) ans = d[i][ans];
	}
	cout << ans << endl;
}


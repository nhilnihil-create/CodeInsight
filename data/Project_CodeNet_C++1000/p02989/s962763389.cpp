#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")



int main() {
	int n;
	cin >> n;
	vector<int>d(n);
	rep(i, n)cin >> d[i];
	sort(d.begin(), d.end());
	cout << d[n / 2] - d[n / 2 - 1] << endl;

	return 0;
}

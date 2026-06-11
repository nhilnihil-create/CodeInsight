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
	rep(i, n) {
		cin >> d[i];
	}
	vector<int>ans(n);
	
	rep(i, n) {
		ans[d[i]-1] = i+1;
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}

	return 0;
}

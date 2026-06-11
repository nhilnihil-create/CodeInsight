#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	int n;
	cin >> n;

	vector<int>x(n);

	for (int i = 0; i < n;i++) {
		cin >> x[i];
	}
	int ans=1000000;

	for (int i = 1; i < 100; i++) {
		int cost=0;
		for (int j = 0; j < n; j++) {
			cost += (x[j] - i)*(x[j] - i);
		}
		ans = min(ans, cost);
	}

	cout << ans << endl;
	return 0;
}
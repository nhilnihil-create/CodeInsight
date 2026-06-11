#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = ll(1e18)+1;

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);

	rep (i,n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	rep(i, n-1) {
		if (a[i]==a[i+1]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES"<< endl;
	return 0;
}
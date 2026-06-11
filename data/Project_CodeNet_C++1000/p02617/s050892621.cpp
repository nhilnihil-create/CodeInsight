#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
#define MOD 1000000007;

int main() {
	int n;
	cin >> n;
	ll V = 0, E = 0;
	rep(i,n) V += ll(i+1)*(n-i);
	rep(i,n-1) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a,b);
		E += ll(a)*(n - b + 1);
	}
	cout << V - E << endl;
	return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 500010
#define MOD 1000000007

int main() {
	int n, q;
	int t, p, l, r;
	ll x;
	fenwick_tree<ll> fw(N);
	cin >> n >> q;
	rep(i, n) {
		cin >> x;
		fw.add(i, x);
	}
	rep(i,q) {
		cin >> t;
		if (t == 0) {
			cin >> p >> x;
			fw.add(p, x);
		}
		else {
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}

	return 0;
}
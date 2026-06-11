#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	ll N; cin >> N;
	ll A;
	map<ll, int> m;

	bool ans = true;

	rep(i, N) {
		cin >> A;
		m[A]++;
		if (m[A] > 1) {
			ans = false;
		}
	}

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}
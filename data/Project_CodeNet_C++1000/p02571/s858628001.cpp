#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
	string S, T;
	cin >> S >> T;
	ll answer = 10000000000000;
	rep(i, S.size() - T.size() + 1) {
		ll b = 0;
		rep(j, T.size()) {
			if (S.at(i + j) != T.at(j)) { b++; }
		}
		answer = min(answer, b);
	}
	cout << answer << endl;
}
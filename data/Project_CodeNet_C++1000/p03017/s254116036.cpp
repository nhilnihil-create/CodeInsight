#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d;
	cin >> s;
	for (int i = a - 1; i < c;i++)if (s.substr(i, 2) == "##") {
		cout << "No" << endl;
		return 0;
	}
	for (int i = b - 1; i < d; i++)if (s.substr(i, 2) == "##") {
		cout << "No" << endl;
		return 0;
	}
	bool ans = false;
	if (d < c) {
		for (int i = b - 2; i < d - 1; i++) {
			if (s.substr(i, 3) == "...")ans = true;
		}
	}
	else ans = true;
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}


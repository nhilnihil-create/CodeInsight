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
	int n,a,b,cnt=0;
	bool ans = false;
	cin >> n;
	rep(i, n) {
		cin >> a >> b;
		if (a == b)cnt++;
		if (a != b)cnt = 0;
		if (3 <= cnt) {
			ans = true;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}


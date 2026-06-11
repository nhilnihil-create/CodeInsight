#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a--, b--, c--, d--;
	string s;
	cin >> s;
	if (c < d) {
		bool e = true;
		for (int i = a; i <= c - 1; i++) {
			string t = s.substr(i, 2);
			if (t == "##") e = false;
		}
		for (int i = b; i <= d - 1; i++) {
			string t = s.substr(i, 2);
			if (t == "##") e = false;
		}
		if (e) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else {
		bool e = false;
		for (int i = b; i <= d; i++) {
			string t = s.substr(i - 1, 3);
			if (t == "...") e = true;
		}
		if (e) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main() {
	solve();
	return 0;
}
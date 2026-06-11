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
	string s;
	cin >> s;
	deque<char> dq;
	rep(i,s.size()) {
		dq.push_back(s[i]);
	}
	int q;
	cin >> q;

	int sw = 0;
	rep(i,q) {
		int t;
		cin >> t;
		if (t == 1) {
			sw = 1 - sw;
		} else {
			int f;
			char c;
			cin >> f >> c;
			if (sw == 0) {
				if (f == 1) dq.push_front(c);
				else dq.push_back(c);
			} else {
				if (f == 2) dq.push_front(c);
				else dq.push_back(c);
			}
		}
	}
	string ans = "";
	if (sw == 0) {
		while(!dq.empty()) {
			char c = dq.front(); dq.pop_front();
			ans += c;
		}
	} else {
		while(!dq.empty()) {
			char c = dq.back(); dq.pop_back();
			ans += c;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
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

char u[3] = {'R', 'G', 'B'};

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if (n <= 2) {
		cout << 0 << endl;
		return;
	}
	int r = 0, g = 0, b = 0;
	rep(i,n) {
		if (s[i] == 'R') r++;
		else if (s[i] == 'G') g++;
		else b++;
	}

	int ng = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			char c1 = s[i];
			char c2 = s[j];
			int k = i + (i - j);
			if (c1 == c2) continue;
			if (k >= n) continue;
			if (c1 != s[k] && c2 != s[k]) ng++;
		}
	}
	cout << (ll) r * g * b - ng << endl;
}

int main() {
	solve();
	return 0;
}
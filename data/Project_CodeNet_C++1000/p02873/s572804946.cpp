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
	int n = s.size();
	vector<int> v(n + 1);
	char c[] = {'<', '>'};
	rep(j,2) {
		rep(i,n) {
			if (s[i] == c[j]) {
				v[i + 1] = max(v[i + 1], v[i] + 1); 
			}
		}
		reverse(ALL(v));
		reverse(ALL(s));
	}
	ll ans = 0;
	rep(i,n + 1) ans += v[i];
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
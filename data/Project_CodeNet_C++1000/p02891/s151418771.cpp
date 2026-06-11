#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	if (s[0] == s[n-1]) {
		bool b = true;
		rep(i,n-1) if (s[i] != s[i+1]) b = false;
		if (b) cout << (ll) n * k / 2 << endl;
		else {
			int x = 1;
			int y = 1;
			rep(i,n-1) {
				if (s[i] == s[i+1]) x++;
				else break;
			}
			for (int i = n-1; i >= 1; i--) {
				if (s[i] == s[i-1]) y++;
				else break;
			}
			int t = 1;
			int z = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == s[i+1]) t++;
				else {
					z += t / 2;
					t = 1;
				}
			}
			z += t / 2;
			cout << (ll) z * k + (k-1) * (- x/2 - y/2 + (x+y)/2) << endl;
		}
	} else {
		int t = 1;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == s[i+1]) t++;
			else {
				ans += t / 2;
				t = 1;
			}
		}
		ans += t / 2;
		cout << ans * k << endl;
	}
}

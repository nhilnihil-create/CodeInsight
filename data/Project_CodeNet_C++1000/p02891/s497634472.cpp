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
	bool b = true;
	rep(i,n-1) if (s[i] != s[i+1]) b = false;
	if (b) {
		cout << (ll) n * k / 2 << endl;
	} else {
		int t = 1;
		ll tot = 0;
		rep(i,n-1) {
			if (s[i] == s[i+1]) t++;
			else {
				tot += t / 2;
				t = 1;
			}
		}
		if (t != 1) tot += t / 2;
		tot *= k;

		if (s[0] != s[n-1]) {
			cout << tot << endl;
		} else {
			ll l = 1;
			ll r = 1;
			rep(i,n-1) {
				if (s[i] == s[i+1]) l++;
				else break;
			}
			for (int i = n-1; i >= 1; i--) {
				if (s[i] == s[i-1]) r++;
				else break;
			}

			cout << tot - l/2*(k-1)- r/2*(k-1) + (l+r)/2*(k-1) << endl;
		}
	}
}
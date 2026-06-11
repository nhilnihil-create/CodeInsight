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
		ll cir = 0;
		int t = 1;
		rep(i,n-1) {
			if (s[i] == s[i+1]) t++;
			else {
				cir += t / 2;
				t = 1;
			}
		}
		cir += t / 2;
		if (s[0] != s[n-1]) cout << cir * k << endl;
		else {
			ll l = 1;
			ll r = 1;
			rep(i,n-1) {
				if (s[i] == s[i+1]) l++;
				else break;
			}
			rep(i,n-1) {
				if (s[n-1-i] == s[n-1-i-1]) r++;
				else break;
			}
			cout << cir * k - (l/2 + r/2 - (l+r)/2) * (k - 1) << endl;
		}
	}
}
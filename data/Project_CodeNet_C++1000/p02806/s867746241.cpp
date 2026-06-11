// Date: 2020-01-23

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

string s[51];
int t[51];
int main() {
	FIO;
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> s[i] >> t[i];
	}
	string x; cin >> x;
	int ans = 0;
	rep(i, 1, n) {
		if(s[i] == x) {
			rep(j, i+1, n) ans += t[j];
			break;
		}
	}
	cout << ans;

	return 0;
}
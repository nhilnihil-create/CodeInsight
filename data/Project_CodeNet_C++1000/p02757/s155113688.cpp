#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;

void solve () {
	int n,p;
	cin >> n >> p;
	string str;
	cin >> str;
	ll ans = 0;
	if (p == 2 || p == 5) {
		for (int i = 0;i < n;++i) {
			int digit = str[i]-'0';
			if (digit%p == 0) ans += i+1;
		}
		cout << ans << '\n';
		return;
	}
	ll suf = 0;
	ll powerOf10 = 1;
	vi cnt(p,0);
	cnt[suf]++;
	for (int i = n-1;i >= 0;--i) {
		int digit = str[i]-'0';
		suf = (suf+digit*powerOf10)%p;
		powerOf10 = (powerOf10*10)%p;
		ans += cnt[suf];
		cnt[suf]++;
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}


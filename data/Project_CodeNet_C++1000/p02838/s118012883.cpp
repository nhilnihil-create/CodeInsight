#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define endl 		"\n"
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1) {std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " : " << arg1;
	ZZ(comma, args...);
}
const ll MOD = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vl a(n + 1);
	rep(i, 1, n + 1)cin >> a[i];
	ll ans = 0ll;
	for (ll i = 0; i < 61; i++) {
		ll z = 0ll, o = 0ll;
		ll k = (1ll << i);
		rep(j, 1, n + 1) {
			if (k & a[j])o++;
			else z++;
		}
		ll kk = k;
		// if (i == 56) {
		// 	trace(k)
		// }
		k %= MOD;
		k = (((k * z) % MOD) * o) % MOD;
		ans = (ans + k) % MOD;
		ans %= MOD;
		// trace(i, kk, z, o, ans, k)
	}
	cout << ans << endl;
}
int main() {
	fast_io;
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}
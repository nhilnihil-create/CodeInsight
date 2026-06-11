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

ll n, k;
bool check(ll d, vl &a) {
	ll cnt = 0;
	rep(i, 0, n) {
		cnt += (a[i] / d);
		if (a[i] % d == 0) {
			cnt--;
		}
		if (cnt > k)return false;
	}
	if (cnt > k)return false;
	else return true;
}
void solve() {
	cin >> n >> k;
	vl a(n);
	ll ma = 0;
	rep(i, 0, n) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	ll lo = 1, hi = ma, ans = hi;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid, a)) {
			hi = mid;
			ans = min(ans, mid);
		}
		else {
			lo = mid + 1;
		}
		// trace(lo, hi, mid)
	}
	cout << ans;
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
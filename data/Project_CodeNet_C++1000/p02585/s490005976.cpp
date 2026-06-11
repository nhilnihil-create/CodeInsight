#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define lb long double
#define pb push_back
#define loop(i,start,n) for(ll i=start;i<n;i++)
#define rloop(i,n,start)for(ll i=n;i>=start;i--)
#define mod 1000000007
#define endl "\n"
#define INF     1e15
#define NEG_INF -1e15
#define pll pair<ll,ll>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//using namespace __gnu_pbds;
ll ans = NEG_INF;
ll p[5010], c[5010];
void solve(ll pos, ll n, ll k){
	ll curr = pos, sum = 0;
	ll tab[5010] = {0};
	vector<ll> dp;
	ll moves = 0;
	while(curr >= 1 && curr <= n && tab[curr] == 0 && moves < k){
		tab[curr] = 1;
		sum += c[p[curr]];
		curr = p[curr];
		ans = max(ans, sum);
		moves++;
		dp.pb(sum);
	}
	if(curr < 1 || curr > n || moves == k)
		return ;

	ll temp = NEG_INF, extra = NEG_INF;
	if(dp.back() >= 0){
		ll times = k / dp.size();
		k = k % dp.size();
		loop(i, 0, k)
			extra = max(extra, dp[i]);
		
		
		temp = dp.back() * times;
		if(times > 0)
			ans = max(ans, max(temp, 0LL) + max(extra, 0LL));
		else
			ans = extra;
		if(times >= 1){
			for(auto &node : dp)
				extra = max(extra, node);

			temp = dp.back() * (times - 1);
			ans = max(ans, max(temp, 0LL) + max(extra, 0LL));
		}
	
	}else{
		loop(i, 0, min((ll)dp.size(), k))
			extra = max(extra, dp[i]);
		ans = max(ans, extra);
	}
	
}
int main(){
	IOS;
	ll n, k;
	cin >> n >> k;
	ll a, b;
	loop(i, 1, n + 1){
		cin >> a;
		p[i] = a;
	}
	loop(i, 1, n + 1){
		cin >> b;
		c[i] = b;
	}

	loop(i, 1, n + 1)
		solve(i, n, k);
	cout << ans << endl;
}
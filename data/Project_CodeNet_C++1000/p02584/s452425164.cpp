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

int main(){
	IOS;
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	ll moves = x / d;
	x -= d * min(moves, k);
	k -= min(moves, k);

	if(k % 2 == 0)
		cout << x << endl;
	else
		cout << abs(x - d) << endl;
}
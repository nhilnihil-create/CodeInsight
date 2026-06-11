#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;
//using namespace atcoder;

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<int>a(n);
	rep(i,n)cin>>a[i],a[i]--;
	vector<vector<int>>dp(60,vector<int>(n,-1));
	rep(i,n){
		dp[0][i]=a[i];
	}
	rep(i,60-1){
		rep(j,n){
			if(dp[i][j]==-1){
				dp[i+1][j]=dp[i][j];
			}
			else{
				dp[i+1][j]=dp[i][dp[i][j]];
			}
		}
	}
	int cur=0;
	rep(i,60){
		if(k&(1LL<<i)){
			cur=dp[i][cur];
		}
	}
	cout<<cur+1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

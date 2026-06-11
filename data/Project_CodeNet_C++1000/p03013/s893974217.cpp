#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

const ll mod = 1e9+7;
//const ll mod = 998244353;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m)cin>>a[i];

	vector<ll> dp(n+9,0);
	dp[0] = 1;
	rep(i,m){
		dp[a[i]] = -1;
	}

	For(i,0,n){
		if(dp[i] == -1) continue;
		dp[i] %= mod;
		if(dp[i+1] != -1) dp[i+1] += dp[i];
		if(dp[i+2] != -1) dp[i+2] += dp[i];
	}
	cout << dp[n] % mod << endl;
}

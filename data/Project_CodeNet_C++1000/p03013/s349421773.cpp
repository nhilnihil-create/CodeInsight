#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(array##_itr, array) { cin >> *(array##_itr); }
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<40;
const int INF = 1<<30;
const double PI=acos(-1);
ll mod                = 1e9 + 7;
int main(){
	int n,m;
	int ans=0;
	cin >>n>>m;
	Vi a(m);
	V dp(n+3,0LL);
	input(a);
//	rep(i, m) { a[i]; }
	a.pb(INF);
	dp[0] = 1LL;
	for (int i = 0; i <= n ; i++) {
		if (i == *(lower_bound(all(a), i))) {
			dp[i] = 0LL;
		}
		dp[i] %= mod;
	//	clog << dp[i] << endl;
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
	}

	cout <<dp[n]%mod << endl;
}
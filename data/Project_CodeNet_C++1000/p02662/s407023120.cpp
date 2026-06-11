#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define rrep(i,n) for(int (i)=1;i<=(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 998244353
#define INF 1e18
#define fcout cout << fixed << setprecision(15)
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

vector<int> dp(3030);

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n, s;
	cin >> n >> s;
	int a[n];
	rep(i, n) cin >> a[i];
	dp[0] = 1;

	rep(i, n) {
		vector<int> cur(s+1);
		rep(j, s+1) {
			if(j + a[i] <= s) cur[j + a[i]] += dp[j], cur[j + a[i]] %= MOD;
			cur[j] += dp[j] * 2, cur[j] %= MOD;
		}
		dp = cur;
	}
	cout << dp[s] << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define rrep(i,n) for(int (i)=1;i<=(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define INF 1e18
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

int h, w;
string s[110];
vector<vector<int>> dp(110, vector<int>(110, INF));

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	
	cin >> h >> w;
	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			if(i == 0 && j == 0) {
				dp[i][j] = s[i][j] == '#';
			} else {
				if(j > 0) {
					chmin(dp[i][j], dp[i][j-1] + (s[i][j-1] == '.' && s[i][j] == '#'));
				}
				if(i > 0) {
					chmin(dp[i][j], dp[i-1][j] + (s[i-1][j] == '.' && s[i][j] == '#'));
				}
			}
		}
	}
	cout << dp[h-1][w-1] << endl;
	// rep(i, h) {
	// 	rep(j, w) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	return 0;
}
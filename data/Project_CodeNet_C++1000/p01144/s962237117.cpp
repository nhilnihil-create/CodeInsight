
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <list>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef unsigned long long ull;
inline ll toInt(string s) { ll v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }


#define For(i,a,b)	for(int (i) = (a);i < (b);(i)++)
#define rep(i,n)	For(i,0,n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define rall(a)		(a).rbegin(), (a).rend()
#define sz(a)		(sizeof(a))
#define Fill(a,v)	fill((int*)a,(int*)(a+(sz(a)/sz(*(a)))),v)

bool cheak(int x, int y, int xMax, int yMax){ return x >= 0 && y >= 0 && xMax > x && yMax > y; }
const int dx[3] = { -1, -1, 0 }, dy[3] = { -1, 0, -1};
const int mod = 1000000007;
const int INF = 1e9;

ll n, m;

int main()
{
	while (cin >> n >> m && n){
		const int M = 10001;
		P dp[M];
		rep(i, n){
			cin >> dp[i].second >> dp[i].first;
		}
		sort(dp, dp + n,greater<P>());
		ll ans = 0;

		rep(i, n){
			if (m){
				if (m >= dp[i].second){
					m -= dp[i].second;
				}
				else{
					ans += (dp[i].second - m)*dp[i].first;
					m = 0;
				}
			}
			else{
				ans += dp[i].second * dp[i].first;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111

	int dp[1<<12];
	void solve(){

			ini(n);
			ini(n1);
			FOR(i,0,1<<12){
				dp[i] = inf;
			}
			dp[0] = 0;
			FOR(i,0,n1){
				ini(x);
				ini(x1);
				int now = 0;
				FOR(i1,0,x1){
					ini(tmp);
					now|=(1<<(tmp-1));
				}
				FOR(i1,0,1<<12)
					dp[i1|now] = min(dp[i1|now],dp[i1]+x);
			}
			if(dp[(1<<n)-1] == inf)out(-1);
			else out(dp[(1<<n)-1]);
		



















	}























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}

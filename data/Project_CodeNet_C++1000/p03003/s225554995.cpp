#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
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


	int mo  = 1e9+7;
	int dp[3100];
	void solve(){

		ini(n);
		ini(n1);
		vi morty(n);
		vi morty1(n1);
		FOR(i,0,n)in(morty[i]);
		FOR(i,0,n1)in(morty1[i]);

		FOR(i,0,n){
			int now = 1;
			FOR(i1,0,n1){
				int now1 = (now+dp[i1])%mo;
				if(morty[i] == morty1[i1]){
					dp[i1]=(dp[i1]+now)%mo;
				}
				now = now1;
			}
		}
		int rick = 1;
		FOR(i,0,3100){
			rick = (rick+dp[i])%mo;
		}
		out(rick);







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

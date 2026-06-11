#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N;
	cin>>N;
	int ans[505][505];
	REP(i,N){
		REP(j,N){
			REP(k,15){
				if((i&1<<k)^(j&1<<k)){
					ans[i][j]=ans[j][i]=k+1;
					break;
				}
			}
		}
	}
	REP(i,N-1){
		FOR(j,i+1,N){
			if(j!=i+1)cout<<" ";
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}

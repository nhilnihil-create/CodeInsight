#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M;
ll S[2001],T[2001];
ll dp[2001][2001];
int main(){
    cin>>N>>M;
	for(ll i=1;i<=N;i++)cin>>S[i];
	for(ll i=1;i<=M;i++)cin>>T[i];
	for(ll i=1;i<=N;i++){
		for(ll j=1;j<=M;j++){
			dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
			dp[i][j]=(dp[i][j]+(dp[i-1][j]-dp[i-1][j-1]+MOD)%MOD)%MOD;
			if(S[i]==T[j]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-1]+1)%MOD;
			}
		}
	}
	cout<<dp[N][M]+1<<endl;
    return 0;
}
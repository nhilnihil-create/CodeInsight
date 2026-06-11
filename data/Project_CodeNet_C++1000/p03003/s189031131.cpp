#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 2005

ll N,M;
ll S[SIZE],T[SIZE];
ll dp[SIZE][SIZE];
vector<int> G[SIZE];


int main(){

	scanf("%lld %lld",&N,&M);

	for(ll i = 0; i < N; i++){

		scanf("%lld",&S[i]);
	}
	for(ll i = 0; i < M; i++){

		scanf("%lld",&T[i]);
	}
	for(ll i = 0; i < N; i++){
		for(ll k = 0; k < M; k++){
			if(S[i] == T[k]){

				G[i].push_back(k+1);
			}
		}
	}


	for(ll i = 0; i <= N; i++){
		for(ll k = 0; k <= M; k++){
			dp[i][k] = 0;
		}
	}

	dp[0][0] = 1;

	for(ll i = 0; i < N; i++){
		//S[i]を無視する場合
		for(ll k = 0; k <= M; k++){
			dp[i+1][k] = dp[i][k];
		}
		//S[i]から遷移する場合
		//遷移高速化のための累積和
		for(ll k = 1; k <= M; k++){
			dp[i][k] += dp[i][k-1];
			dp[i][k] %= MOD;
		}
		//printf("i:%lld\n",i);
		for(ll k = 0; k < G[i].size(); k++){

			dp[i+1][G[i][k]] += dp[i][G[i][k]-1];
			//printf("%lldに%lld加算\n",G[i][k],dp[i][G[i][k]-1]);
			dp[i+1][G[i][k]] %= MOD;
		}
	}

	ll ans = 0;
	for(ll i = 0; i <= M; i++){

		ans += dp[N][i];
		ans %= MOD;
	}

	printf("%lld\n",ans);

	return 0;
}

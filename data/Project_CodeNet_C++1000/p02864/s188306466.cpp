#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 305

ll N,K;
ll H[SIZE];
ll dp[SIZE][SIZE]; //dp[右端の列][削除個数] = 最小コスト

int main(){

	scanf("%lld %lld",&N,&K);

	H[0] = 0;

	for(int i = 1; i <= N; i++){

		scanf("%lld",&H[i]);
	}
	H[N+1] = 0;

	ll ans = 0;

	if(K == 0){

		for(int i = 0; i <= N-1; i++){

			ans += max(0LL,H[i+1]-H[i]);
		}

		printf("%lld\n",ans);

		return 0;
	}

	for(int i = 0; i <= N+1; i++){
		for(int k = 0; k <= K; k++){

			dp[i][k] = HUGE_NUM;
		}
	}

	dp[0][0] = 0;

	for(ll i = 1; i <= N+1; i++){ //今回の列
		for(ll a = max(0LL,i-K-1); a <= i-1; a++){ //1つ前の列
			ll add = (i-1)-(a+1)+1;
			for(ll b = 0; b <= K; b++){ //削除個数
				if(b+add > K)break;

				dp[i][b+add] = min(dp[i][b+add],dp[a][b]+max(0LL,H[i]-H[a]));
			}
		}
	}

	ans = HUGE_NUM;

	for(ll i = 0; i <= K; i++){

		ans = min(ans,dp[N+1][i]);
	}

	printf("%lld\n",ans);

	return 0;
}

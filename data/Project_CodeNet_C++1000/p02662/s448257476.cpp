#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
//#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define MOD 998244353

#define SIZE 3005


ll N,S;
ll A[SIZE];
ll dp[SIZE][SIZE];


int main(){

	scanf("%lld %lld",&N,&S);

	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}

	for(int i = 0; i < SIZE; i++){
		for(int k = 0; k < SIZE; k++){

			dp[i][k] = 0;
		}
	}

	//dp[何個見たか][和] = 場合の数
	dp[0][0] = 1;

	for(int i = 0; i < N; i++){

		//足さない
		for(int k = 0; k < SIZE; k++){

			dp[i+1][k] += 2*dp[i][k];
			dp[i+1][k] %= MOD;
		}
		//足す
		for(int k = 0; k+A[i] < SIZE; k++){

			dp[i+1][k+A[i]] += dp[i][k];
			dp[i+1][k+A[i]] %= MOD;
		}
	}

	printf("%lld\n",dp[N][S]);

	return 0;
}

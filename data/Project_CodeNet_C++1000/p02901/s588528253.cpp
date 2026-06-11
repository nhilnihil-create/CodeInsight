#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N,M;
int POW[13];
int A[1005],num[1005];
int table[1005][13];
int dp[1 << 14];


int main(){

	POW[0] = 1;
	for(int i = 1; i < 13; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d %d",&N,&M);

	dp[0] = 0;
	for(int state = 1; state < POW[N]; state++){

		dp[state] = BIG_NUM;
	}

	for(int i = 0; i < M; i++){

		scanf("%d %d",&A[i],&num[i]);

		int tmp = 0;

		for(int k = 0; k < num[i]; k++){

			scanf("%d",&table[i][k]);
			tmp += POW[table[i][k]-1];
		}

		dp[tmp] = min(dp[tmp],A[i]);
	}

	for(int state = 0; state < POW[N]-1; state++){
		if(dp[state] == BIG_NUM)continue;
		for(int adj_state = 1; adj_state < POW[N]; adj_state++){
			if(dp[adj_state] == BIG_NUM)continue;

			int next_state = state|adj_state;
			if(next_state == state || next_state == adj_state)continue;

			int next_cost = dp[state]+dp[adj_state];

			dp[next_state] = min(dp[next_state],next_cost);
		}
	}

	if(dp[POW[N]-1] == BIG_NUM){

		printf("-1\n");

	}else{

		printf("%d\n",dp[POW[N]-1]);
	}

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

char L[SIZE];
ll dp[2][SIZE];


int main(){

	scanf("%s",L);

	int len;
	for(len = 0; L[len] != '\0'; len++);

	for(int i = 0; i < 2; i++){
		for(int k = 0; k <= len; k++){
			dp[i][k] = 0;
		}
	}

	dp[true][0] = 2;//dp[Lと一致しているか][Lのインデックス] = 場合の数
	dp[false][0] = 1;

	for(int i = 1; i < len; i++){
		//trueからの遷移
		if(L[i] == '1'){

			dp[true][i] = dp[true][i-1]*2; //(a,b) = (1,0),(0,1)
			dp[true][i] %= MOD;

			dp[false][i] += dp[true][i-1]; //この桁は(a,b) = (0,0)
			dp[false][i] %= MOD;

		}else{ //L[i] == '0'

			dp[true][i] = dp[true][i-1]; //(a,b) = (0,0)
		}

		dp[false][i] += dp[false][i-1]*3; //(a,b) = (1,0),(0,1),(0,0)
		dp[false][i] %= MOD;
	}

	printf("%lld\n",(dp[true][len-1]+dp[false][len-1])%MOD);

	return 0;
}

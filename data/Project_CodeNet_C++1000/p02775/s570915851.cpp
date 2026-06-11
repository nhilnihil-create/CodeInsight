#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 1000005

string line;
ll dp[SIZE][2];

int main(){

	cin >> line;
	line = '0'+line;

	int N = line.length();

	for(int i = 0; i <= N; i++){
		dp[i][0] = HUGE_NUM;
		dp[i][1] = HUGE_NUM;
	}

	dp[0][0] = 0;

	for(int i = 0; i < N; i++){

		ll num = line[i]-'0';

		dp[i+1][0] = min(dp[i+1][0],dp[i][0]+num);
		dp[i+1][1] = min(dp[i+1][1],dp[i][0]+num+1);

		dp[i+1][0] = min(dp[i+1][0],dp[i][1]+10-num);
		dp[i+1][1] = min(dp[i+1][1],dp[i][1]+9-num);
	}

	printf("%lld\n",dp[N][0]);

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 3005

struct Info{
	bool operator<(const struct Info &arg) const{

		return TIME < arg.TIME;
	}
	int TIME,value;
};

int dp[2][2*SIZE];
Info info[SIZE];


int main(){

	int N,T;
	scanf("%d %d",&N,&T);

	for(int i = 0; i < N; i++){

		scanf("%d %d",&info[i].TIME,&info[i].value);
	}

	sort(info,info+N);

	int CURRENT = 0,NEXT = 1;
	for(int k = 0; k < 2*SIZE; k++){

		dp[CURRENT][k] = -BIG_NUM;
	}


	dp[CURRENT][0] = 0;

	for(int i = 0; i < N; i++){
		for(int k = 0; k < 2*SIZE; k++){

			dp[NEXT][k] = dp[CURRENT][k];
		}

		for(int k = 0; k <= T-1; k++){
			if(dp[CURRENT][k] == -BIG_NUM)continue;

			dp[NEXT][k+info[i].TIME] = max(dp[NEXT][k+info[i].TIME],dp[CURRENT][k]+info[i].value);
		}
		swap(CURRENT,NEXT);
	}

	int ans = 0;

	for(int i = 0; i < 2*SIZE; i++){

		ans = max(ans,dp[CURRENT][i]);
	}

	printf("%d\n",ans);

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 2005

struct Info{

	bool operator<(const struct Info &arg) const{

		return value > arg.value;
	}
	ll value,loc;
};

ll N;
ll dp[SIZE][SIZE];
Info info[SIZE];


int main(){

	scanf("%lld",&N);

	for(int i = 0; i < N; i++){

		scanf("%lld",&info[i].value);
		info[i].loc = i;
	}
	sort(info,info+N);

	//dp[処理済みの個数][左に移動する個数]
	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= N; k++){
			dp[i][k] = 0;
		}
	}

	for(ll i = 0; i < N; i++){
		//printf("\ninfo[%lld].value:%lld loc:%lld\n",i,info[i].value,info[i].loc);
		for(ll k = 0; k <= i; k++){
			ll num_R = i-k;

			//printf("k;%lld dp[i][k]:%lld\n",k,dp[i][k]);
			//左
			dp[i+1][k+1] = max(dp[i+1][k+1],dp[i][k]+abs(k-info[i].loc)*info[i].value);
			//printf("左:%lld\n",dp[i+1][k+1]);

			//右
			dp[i+1][k] = max(dp[i+1][k],dp[i][k]+abs((N-1-num_R)-info[i].loc)*info[i].value);
			//printf("to:%lld 位置差分:%lld 右:%lld\n",N-1-num_R,abs((N-k-1)-info[i].loc),dp[i+1][k]);
		}
	}

	ll ans = 0;
	for(ll i = 0; i <= N; i++){

		ans = max(ans,dp[N][i]);
	}

	printf("%lld\n",ans);

	return 0;
}

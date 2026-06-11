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

		return A < arg.A;
	}
	int A,B;
};

int N,T;
int dp[SIZE][SIZE];
Info info[SIZE];

int main(){

	scanf("%d %d",&N,&T);

	for(int i = 0; i < N; i++){

		scanf("%d %d",&info[i].A,&info[i].B);
	}
	sort(info,info+N);

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= T-1; k++){

			dp[i][k] = 0;
		}
	}

	/*
	 * 注文する集団内で一番時間がかかるものは、
	 * T-1に注文した方が良い
	 * →一番時間がかかる料理で場合分けできる
	 * →昇順にdpすれば良い
	 * */

	int ans = 0;

	for(int a = 0; a < N; a++){ //料理のループ

		ans = max(ans,dp[a][T-1]+info[a].B); //料理aを最後に注文する
		if(a == N-1)break;

		for(int t = 0; t <= T-1; t++){

			dp[a+1][t] = dp[a][t];
		}

		for(int t = T-1; t-info[a].A >= 0; t--){

			dp[a+1][t] = max(dp[a+1][t],dp[a][t-info[a].A]+info[a].B);
		}
		for(int t = 1; t <= T-1; t++){

			dp[a+1][t] = max(dp[a+1][t],dp[a+1][t-1]);
		}
	}

	printf("%d\n",ans);

	return 0;
}

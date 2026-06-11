#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

const long long INF = (1LL<<62);

LL H, N;
vector<LL> A; //威力
vector<LL> B; //魔力
LL dp[1004][10004] = {INF};


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> N;
	for(int i=0; i<N; i++){
		LL a, b;
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}

	for(int i=0; i<1004; i++){
		for(int j=0; j<10004; j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<=H; j++){
			//i番目の魔法を使わない場合
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			//i番目の魔法を使う場合
			dp[i+1][min(j+A[i], H)] = min(dp[i+1][min(j+A[i], H)], dp[i+1][j]+B[i]);
		}
	}
    LL ans = dp[N][H];
	printf("%lld\n", ans);
	return 0;
}

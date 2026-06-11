#include <cstdio>
using namespace std;

int main(){
	int dp[31] = {1, 1, 2};
	for(int i = 3; i <= 30; ++i){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	int n;
	while(scanf("%d", &n), n){
		printf("%d\n", (dp[n] + 3649) / 3650);
	}
}
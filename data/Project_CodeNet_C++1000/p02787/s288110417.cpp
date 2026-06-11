#include<iostream>

const static int INF = 1001001001;

int main(void){
    int h, n;
    std::cin >> h >> n;
    int dp[n+1][h+1];

    for(int i = 0; i < n+1; i++){
	for(int j = 0; j < h+1; j++){
	    dp[i][j] = INF;
	}
    }
    for(int i = 0; i < n+1; i++){
	dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++){
	int a, b;
	std::cin >> a >> b;
	for(int j = 0; j <= h; j++){
	    dp[i+1][j] = dp[i][j];
	}
	for(int j = 0; j <= h; j++){
	    int nj = std::min(j + a, h);
	    dp[i+1][nj] = std::min(dp[i+1][nj], dp[i+1][j] + b);
	}
    }
    std::cout << dp[n][h] << std::endl;
    return 0;
}


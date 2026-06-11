#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




#define SIZE 105

int H,W;
int dp[SIZE][SIZE];
char table[SIZE][SIZE];

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",table[row]);
	}

	if(table[0][0] == '#'){

		dp[0][0] = 1;

	}else{

		dp[0][0] = 0;
	}

	for(int col = 1; col < W; col++){
		if(table[0][col] == '#' && table[0][col-1] == '.'){

			dp[0][col] = dp[0][col-1]+1;

		}else{

			dp[0][col] = dp[0][col-1];
		}
	}

	for(int row = 1; row < H; row++){
		if(table[row][0] == '#' && table[row-1][0] == '.'){

			dp[row][0] = dp[row-1][0]+1;

		}else{

			dp[row][0] = dp[row-1][0];
		}
	}

	for(int row = 1; row < H; row++){
		for(int col = 1; col < W; col++){
			if(table[row][col-1] == '.' && table[row][col] == '#'){

				dp[row][col] = dp[row][col-1]+1;

			}else{

				dp[row][col] = dp[row][col-1];
			}

			if(table[row][col] == '#' && table[row-1][col] == '.'){

				dp[row][col] = min(dp[row][col],dp[row-1][col]+1);

			}else{

				dp[row][col] = min(dp[row][col],dp[row-1][col]);
			}
		}
	}

	printf("%d\n",dp[H-1][W-1]);

	return 0;
}

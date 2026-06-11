#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int ans, h, w;
char masu[100][100];
int dp[100][100];


int main(){
	cin >> h >> w;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> masu[i][j];
		}
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			dp[i][j] = MOD;
		}
	}

	dp[0][0] = 0;
	for (int i = 1; i < h; i++){
		dp[i][0] = dp[i-1][0];
		if (masu[i-1][0] == '#' && masu[i][0] == '.'){
			dp[i][0]++;
		}
	}
	for (int i = 1; i < w; i++){
		dp[0][i] = dp[0][i-1];
		if (masu[0][i-1] == '#' && masu[0][i] == '.'){
			dp[0][i]++;
		}
	}

	for (int i = 1; i < h; i++){
		for (int j = 1; j < w; j++){
			if (masu[i-1][j] == '#' && masu[i][j] == '.'){
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			}else{
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
			if (masu[i][j-1] == '#' && masu[i][j] == '.'){
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
			}else{
				dp[i][j] = min(dp[i][j], dp[i][j-1]);
			}
		}
	}

	if (masu[h-1][w-1] == '#') dp[h-1][w-1]++;
	cout << dp[h-1][w-1] << endl;
	return 0;
}

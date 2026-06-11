#include <bits/stdc++.h>
#define ll long long int
#define booga cout << "booga" << endl
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

const int INF= 1e9 + 5;

void min_self(int &a, int b){
	a = min(a,b);
}

void testcase(){
	int H,W;
	cin >> H >> W;
	vector<string> grid(H);
	for(int i{0};i < H;i++){
		cin >> grid[i];
	}
	vector<vector<int>> dp(H,vector<int>(W,INF));
	dp[0][0] = grid[0][0] == '#';
	for(int i{0};i < H;i++){
		for(int j{0};j < W;j++){
			if(i == 0 && j == 0){
				continue;
			}
			if(i == 0){
				min_self(dp[i][j],dp[i][j-1] + (grid[i][j-1] == '.' && grid[i][j] == '#'));
			}
			else if(j == 0){
				min_self(dp[i][j],dp[i-1][j] + (grid[i-1][j] == '.' && grid[i][j] == '#'));
			}
			else{
				min_self(dp[i][j],dp[i][j-1] + (grid[i][j-1] == '.' && grid[i][j] == '#'));
				min_self(dp[i][j],dp[i-1][j] + (grid[i-1][j] == '.' && grid[i][j] == '#'));
				
			}
		}
	}
	cout << dp[H-1][W-1] << endl;
}
	

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	t = 1;
	while(t--){
		testcase();
	}
	return 0;
}


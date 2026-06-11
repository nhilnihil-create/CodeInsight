#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int w, h, n; 
int dp[20][20];// x y
bool memo[20][20];// x y
int main(void){
	while(1){
		rep(i, 20)rep(j, 20){//?????????
			dp[i][j] = 0;
			memo[i][j] = false;
		}

		cin >> w >> h;
		if(w == 0 && h == 0) return 0;
		cin >> n;
		rep(i, n){
			int x, y; cin >> x >> y;
			x--; y--;
			memo[x][y] = true;//??\???
		}
		dp[0][0] = 1;// x = 0, y = 0???????????????????????§????????????????????°
		for (int x = 0; x < w; ++x){
			for (int y = 0; y < h; ++y){
				if(memo[x][y]) continue;
				//?????????dp
				if(0 <= x - 1 && x - 1 < w){
					dp[x][y] += dp[x - 1][y];
				}
				if(0 <= h - 1 && h - 1 < h){
					dp[x][y] += dp[x][y - 1];
				}
			}
		}
		cout << dp[w - 1][h - 1] << endl;
	}
}
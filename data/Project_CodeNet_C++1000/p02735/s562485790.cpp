#include <bits/stdc++.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	
	int dp[100][100];
	bool s[100][100];

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char c; cin >> c;
			s[i][j] = (c == '.');
		}
	}
	
	dp[0][0] = (s[0][0] ? 0 : 1);

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i == 0 && j == 0)
				continue;

			int u = (i == 0) ? INT_MAX : dp[i-1][j];
			int l = (j == 0) ? INT_MAX : dp[i][j-1];
			if(s[i][j]){ // white
				dp[i][j] = min(u,l);
			} else { //black
				if(i > 0){
					if(j > 0){
						dp[i][j] = min(	(s[i-1][j] ? 1 : 0) + u,
										(s[i][j-1] ? 1 : 0) + l);
					} else {
						dp[i][j] = (s[i-1][j] ? 1 : 0) + u;
					}
				} else {
					dp[i][j] = (s[i][j-1] ? 1 : 0) + l;
				}
			}
		}
	}

	cout << dp[h-1][w-1];

	return 0;
}

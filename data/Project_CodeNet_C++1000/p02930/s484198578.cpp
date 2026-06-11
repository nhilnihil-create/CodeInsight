#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i) = (0);(i) < (n);++i)

int ans[555][555];
int main(){
	int n;cin >> n;
	REP(i, n){
		REP(j, n){
			if(i == j)continue;
			for(int k = 30;k >= 0;k--){
				if((i & (1 << k)) != (j & (1 << k))){
					ans[i][j] = (k + 1);
					break;
				}
			}
		}
	}
	REP(i, n-1){
		REP(j, n){
			if(i < j)cout << ans[i][j] << (j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

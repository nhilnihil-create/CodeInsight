#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int ans[1005][1005];

int main(){
	int h,w,a,b;
	cin >> h >> w >> a >> b;
	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if(i < b && j < a) ans[i][j]++;
			if(i >= b && j >= a) ans[i][j]++;
		}
	}
	
	rep(i,h){
		rep(j,w){
			cout << ans[i][j];
		}
		cout << endl;
	}
	
    return 0;
}


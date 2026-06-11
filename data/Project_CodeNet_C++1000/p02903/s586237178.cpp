#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int h,w;
	cin >> h >> w;
	int a,b;
	cin >> a >> b;
	int ans[1005][1005];
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i<b && j<a){
				ans[i][j] = 1;
			} else if (i < b && j >= a){
				ans[i][j] = 0;
			} else if (i >= b && j < a){
				ans[i][j] = 0;
			}else{
				ans[i][j] = 1;
			}
		}
	}
	
for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,x,y;
	// nyuryoku
	cin >> n >> x >> y;
	map<int,int> ans;
	// keisan
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int dmin;
			dmin = min(abs(j-i),abs(x-i)+abs(y-j)+1);
			ans[dmin]++;
		}
	}
	// syutsuryoku
	for(int i=1;i<n;i++){
		cout << ans[i] << endl;
	}
}

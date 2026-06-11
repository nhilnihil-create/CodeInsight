#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

int main(){
	int m, mn, mx;
	while(cin>>m>>mn>>mx, m|mn|mx){
		int P[205], diff=0, ans=0;
		rep(i,m) cin >> P[i+1];
		for(int i=mn; i<=mx; i++){
			if( P[i] - P[i+1] >= diff ){
				ans = i;
				diff = P[i] - P[i+1];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
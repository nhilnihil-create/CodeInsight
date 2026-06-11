#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	LL l,r;
	// nyuryoku
	cin >> l >> r;
	// keisan
	if(r - l > 2019){
		cout << '0';
		return 0;
	}else{
		LL ans = 2018;
		for(LL i=l;i<=r-1;i++){
			for(LL j=i+1;j<=r;j++){
				ans = min(ans,i*j%2019);
			}
		}
		cout << ans;
		return 0;
	}
	// syutsuryoku
}
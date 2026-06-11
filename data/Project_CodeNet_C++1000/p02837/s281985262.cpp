#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n],x[n][n],y[n][n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		for(int j=0;j<a[i];j++){
			cin >> x[i][j] >> y[i][j];
		}
	}
	// keisan
	int ans = 0;
	for(int bit = 0;bit < (1<<n);bit++){
		int kari = 0;
		int flag = 1;
		for(int i=0;i<n;i++){
			if(bit & (1<<i)){
				kari++;
				for(int j=0;j<a[i];j++){
					int s = x[i][j] -1;
					if(y[i][j] == 1){
						if(bit & (1<<s)){
							continue;
						}else{
							flag = 0;
						}
					}else{
						if(bit & (1<<s)){
							flag = 0;
						}else{
							continue;
						}
					}
				}
			}
		}
		if(flag){
			ans = max(ans,kari);
		}
	}
	// syutsuryoku
	cout << ans << endl;
}
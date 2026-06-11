#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,d;
	// nyuryoku
	cin >> n >> d;
	int x[n][d];
	for(int i=0;i<n;i++){
		for(int j=0;j<d;j++){
			cin >> x[i][j];
		}
	}
	// keisan
	int ans = 0;
	for(int i=0;i<n-1;i++){
		int wa = 0;
		for(int j=i+1;j<n;j++){
			wa = 0;
			for(int k=0;k<d;k++){
				wa += (x[i][k] - x[j][k])*(x[i][k] - x[j][k]);
			}
			if(floor(sqrt(wa)) == sqrt(wa)){
				ans++;
			}
		}
		
	}
	// syutsuryoku
	cout << ans << endl;
}
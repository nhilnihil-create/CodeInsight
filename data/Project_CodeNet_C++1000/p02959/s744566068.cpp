#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	LL a[n+1],b[n];
	for(int i=0;i<n+1;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	LL ans = 0;
	// keisan
	for(int i=0;i<n;i++){
		if(b[i] < a[i]){
			ans += b[i];
		}else{
			ans += a[i];
			b[i] -= a[i];
			if(b[i] > 0){
				if(b[i] < a[i+1]){
					a[i+1] -= b[i];
					ans += b[i];
				}else{
					ans += a[i+1];
					a[i+1] = 0;
				}
			}
		}
	}
	// syutsuryoku
	cout << ans;
}
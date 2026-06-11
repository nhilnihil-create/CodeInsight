#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,h;
	// nyuryoku
	cin >> h >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	// keisan
	LL dp[h+1];
	for(int i=0;i<=h;i++){
		dp[i] = 200000000;
	}
	dp[0] = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			dp[min(i+a[j],h)] = min(dp[min(i+a[j],h)],dp[i]+b[j]);
		}
	}
	// syutsuryoku
	cout << dp[h] << endl;
}
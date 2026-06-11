#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int dp[a[n-1]+1];
	for(int i=0;i<=a[n-1];i++){
		dp[i] = 1;
	}
	int ans = 0;
	// keisan
	for(int i=0;i<n;i++){
		int b = a[i];
		for(int j=b*2;j<=a[n-1];j += b){
			dp[j] = 0;
		}
		if(i != n-1){
			if(a[i] == a[i+1]){
				dp[b] = 0;
			}
		}
		if(dp[b] != 0){
			ans++;
		}
	}
	// syutsuryoku
	cout << ans;
}
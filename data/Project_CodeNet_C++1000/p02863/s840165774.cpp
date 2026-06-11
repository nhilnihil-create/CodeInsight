#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 3e3 + 7;
int dp1[maxn][maxn],dp2[maxn][maxn];
int a[maxn],b[maxn];
int main()
{
	int n,t;
	cin >> n >> t;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < t;j++){
			dp1[i][j] = dp1[i - 1][j];
			if(j >= a[i]){
				dp1[i][j] = max(dp1[i][j],dp1[i - 1][j - a[i]] + b[i]);
			}
		}
	}
	for(int i = n;i >= 1;i--){
		for(int j = 0;j < t;j++){
			dp2[i][j] = dp2[i + 1][j];
			if(j >= a[i]){
				dp2[i][j] = max(dp2[i][j],dp2[i + 1][j - a[i]] + b[i]);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < t;j++){
			ans = max(ans,dp1[i - 1][j] + dp2[i + 1][t - j -1] + b[i]);
		}
	}
	cout << ans << endl;
	return 0;
 } 
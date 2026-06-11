#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define ll long long
const int N = 2005;
const ll mod = 1e9+7;

int n,m,a[N],b[N];
ll dp[N][N],sum[N][N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(a[i] == b[j]) dp[i][j] = sum[i-1][j-1] + 1;
			else dp[i][j] = 0;
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j];
			dp[i][j] %= mod;
			sum[i][j] %= mod;
	}
	cout << (sum[n][m] + 1 + mod) % mod;
}
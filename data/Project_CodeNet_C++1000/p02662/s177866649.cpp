#include "bits/stdc++.h"
using namespace std;
const long long m = 998244353;
long long int dp[3001][3001];
long long binpow(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
	int n,s;
	cin >> n >> s;
	int vet[3001];
	for(int i=0;i<n;i++) cin >> vet[i];
	dp[0][0]=binpow(2,n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++) if(!(i==0 && j==0))dp[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=(dp[i][j]%m + dp[i-1][j]%m)%m;
			if((j+vet[i-1])<=s) dp[i][j+vet[i-1]] = (dp[i][j+vet[i-1]]%m + (dp[i-1][j]*499122177)%m)%m; 
		}
	}
	cout << (dp[n][s]+m)%m << endl;
}
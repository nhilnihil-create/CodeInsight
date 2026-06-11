#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;
int arr[maxn],idxs[maxn];
ll dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i] , idxs[i] = i;
	sort(idxs+1,idxs+1+n,[=](int a,int b)->bool
		{return arr[a] > arr[b];});
	
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) {
		int pos = idxs[i] , coe = arr[idxs[i]];
		for(int j=0;j<=i;j++) {
			ll a = 0  , b = 0;
			if(j != 0)	a = (ll)coe * abs(pos - j) + dp[i - 1][j - 1];
			if(j != i)	b = (ll)coe * abs(pos - (n - (i - j) + 1)) + dp[i - 1][j];
			dp[i][j] = max(a,b);
		}
	}
	cout << *max_element(dp[n]+1,dp[n]+1+n) << endl;
	return 0;
}

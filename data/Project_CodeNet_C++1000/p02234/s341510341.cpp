#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)
#define s(c) static_cast<int>((c).size())

int main(){
	int n;
	cin >> n;
	int i, t, A[n+1];
	cin >> A[0] >> A[1];
	for(i = 2; i <= n; i++){
		cin >> t >> A[i];
	}

	//dp[l][r] -> min(A[l]*...*A[r])
	int dp[n][n+1]{}, dplr, l, r;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n-i; j++){
			l = j;
			r = j+i;
			dplr = INT_MAX;
			for(int k = l; k < r; k++){
				dplr = min(dplr, dp[l][k] + dp[k+1][r] + A[l]*A[k+1]*A[r+1]);
			}
			dp[l][r] = dplr;
			//printf("[%d, %d]=%d ", l, r, dplr);
		}
		//printf("\n");
	}

	printf("%d\n", dp[0][n-1]);
}


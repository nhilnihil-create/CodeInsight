#include<bits/stdc++.h>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF (1 << 29)

static const int MAX = 3000;

using namespace std;

int main(){
	int n; cin >> n; 
	long dp[MAX][MAX];
	vector<pair<int, int> > A;

	for(int i = 0; i < n; i++){
		int a; cin >> a;
		A.pb(make_pair(a, i));
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());

	long m = 0;	

	for(long i = 0; i <= n; i++)
		for(long j = 0; j <= n; j++)
			dp[i][j] = 0; 

	for(long l = 0; l <= n; l++){
		for(long r = 0; r <= n; r++){
			if(l + r == n){
				m = max(m, dp[l][r]);
				break;
			}

			long act = A[l + r].first, idx = A[l + r].second;

			dp[l + 1][r] = max(dp[l + 1][r], 
					dp[l][r] + act * abs(idx - l));
			dp[l][r + 1] = max(dp[l][r + 1], 
					dp[l][r] + act * abs(idx - (n - 1 - r)));
		}
	}

	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << m << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int mxN = 3005;
int dp1[3005][3005], dp2[3005][3005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int N, T;
	cin>>N>>T;
	vector<int> A(N + 1), B(N + 1);
	for(int i = 1; i <= N; i++){
		cin>>A[i]>>B[i];
	}
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	for(int i = 1; i <= N; i++){
		for(int sum = 0; sum < T; sum++){
			dp1[i][sum] = dp1[i - 1][sum];
			if(sum >= A[i])dp1[i][sum] = max(dp1[i][sum], dp1[i - 1][sum - A[i]] + B[i]);
		}
	}
	for(int i = N; i >= 1; i--){
		for(int sum = 0; sum < T; sum++){
			dp2[i][sum] = dp2[i + 1][sum];
			if(sum >= A[i])dp2[i][sum] = max(dp2[i][sum], dp2[i + 1][sum - A[i]] + B[i]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int sum = 0; sum < T; sum++){
			ans = max(ans, dp1[i - 1][sum] + dp2[i + 1][T - 1 - sum] + B[i]);
		}
	}
	cout<<ans<<endl;

	return 0;
}
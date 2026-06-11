#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);
const LL P = 1000000007LL;

LL dp[100002] = {0};
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> A;
	map<LL, vector<int>> M;
	for(int i=0; i<N; i++){
		LL a; cin >> a;
		A.push_back(a);
		M[a].push_back(i);
		if(M[a].size() > 3){
			printf("0\n"); return 0;
		}
	}

	if(A[0] != 0){
		printf("0\n"); return 0;
	}

	if(N == 1){
		printf("3\n"); return 0;
	}
	if(N == 2){
		if(A[1] == 0){
			printf("6\n");
		}
		else if(A[1] == 1){
			printf("3\n");
		}
		return 0;
	}

	// N>=3
	if(A[0] == 0 && A[1] == 0 && A[2] == 0) dp[2] = 6;
	if(A[0] == 0 && A[1] == 0 && A[2] == 1) dp[2] = 12;
	if(A[0] == 0 && A[1] == 0 && A[2] == 2) dp[2] = 0;
	if(A[0] == 0 && A[1] == 1 && A[2] == 0) dp[2] = 6;
	if(A[0] == 0 && A[1] == 1 && A[2] == 1) dp[2] = 0;
	if(A[0] == 0 && A[1] == 1 && A[2] == 2) dp[2] = 3;

	if(N == 3){
		printf("%lld\n", dp[2]); return 0;
	}

	for(int i=3; i<N; i++){
		if(A[i] == 0){
			if(A[i-1] == i-1){
				dp[i] = 2*dp[i-1];
				dp[i] %= P;
			}
			else{
				dp[i] = dp[i-1];
				dp[i] %= P;
			}
		}
		else{
			if(M.count(A[i]-1) == 0){
				printf("0\n"); return 0;
			}
			int s = 0, t = 0;
			for(int j=0; j<M[A[i]-1].size(); j++){
				if(M[A[i]-1][j] < i) s++;
			}
			for(int j=0; j<M[A[i]].size(); j++){
				if(M[A[i]][j] < i) t++;
			}
			if(s - t <= 0 || s > 3 || t > 2){
				printf("0\n"); return 0;
			}
			dp[i] = (s-t)*dp[i-1];
			dp[i] %= P;
		}
		dp[i] %= P;
		if(dp[i] < 0) dp[i] += P;
	}
	printf("%lld\n", dp[N-1]);
	return 0;
}

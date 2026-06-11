#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
const int INF = 1<<30;
const int N_MAX = 1000000;

int dp[N_MAX];
int dpOdd[N_MAX];

int main() {
	rep(i,N_MAX) {
		dp[i] = INF;
		dpOdd[i] = INF;
	}
	dp[0] = dpOdd[0] = 0;
	int n=1;
	while(n*(n+1)*(n+2)/6 < N_MAX) {
		int v = n*(n+1)*(n+2)/6;
		for(int i=v; i<N_MAX; i++) {
			dp[i] = min( dp[i], dp[i-v]+1 );
		}
		n++;
	}
	n=1;
	while(n*(n+1)*(n+2)/6 < N_MAX) {
		int v = n*(n+1)*(n+2)/6;
		for(int i=v; i<N_MAX; i++) {
			dpOdd[i] = min( dpOdd[i], dpOdd[i-v]+1 );
		}
		do{ n++; } while((n*(n+1)*(n+2)/6)%2==0);
	}
	while(cin >> n, n) {
		cout << dp[n] << ' ' << dpOdd[n] << endl;
	}
	return 0;
}
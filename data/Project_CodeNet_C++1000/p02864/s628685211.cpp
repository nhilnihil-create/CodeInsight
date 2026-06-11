#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n,k;
	std::cin >> n >> k;
	std::vector<int> h(n+1,0);
	rep(i,n) std::cin >> h[i+1];

	const int INF = 1e16;
	std::vector<std::vector<std::vector<int> > > dp(n+1,std::vector<std::vector<int> >(k+1,std::vector<int>(n+1,INF)));
	dp[0][0][0]=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<=k;j++) {
			for(int l=0;l<=i;l++) {
				if(dp[i][j][l]==INF) continue;
				dp[i+1][j][i+1] = std::min(dp[i+1][j][i+1],dp[i][j][l]+std::max(0ll,h[i+1]-h[l]));
				if(j<k) dp[i+1][j+1][l] = std::min(dp[i+1][j+1][l],dp[i][j][l]);
			}
		}
	}
	int min = INF;
	for(int j=0;j<=k;j++) {
		for(int l=0;l<=n;l++) {
			min = std::min(min,dp[n][j][l]);
		}
	}
	print(min);

	return 0;
}

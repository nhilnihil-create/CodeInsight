#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;

int main()
{
	int n;
	while(scanf("%d", &n), n){
		int dp[10][10];
		memset(dp, INF, sizeof(dp));
		int V = 0;
		rep(i, n){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			dp[a][b] = dp[b][a] = c;
			V = max(V, max(a, b)+1);
		}
		rep(i, V)
			dp[i][i] = 0;
		rep(k, V) rep(i, V) rep(j, V)
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		
		int best = INF;
		int ansi = -1;
		rep(i, V){
			int sum = accumulate(dp[i], dp[i]+V, 0);
			if(sum < best){
				best = sum;
				ansi = i;
			}
		}
		printf("%d %d\n", ansi, best);
	}
	return 0;
}
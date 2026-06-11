#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N (105)
#define MAX_R (105)
#define MAX_C (105)
#define INF (MAX_N * MAX_R * MAX_C)

int r[MAX_N];
int c[MAX_N];
int dp[MAX_N][MAX_N];
int n;

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
	scanf("%d %d", &r[i], &c[i]);
    }
    
    for ( int l = 1; l <= n; l++ ) {
	for ( int h = 0; h <= n - l; h++ ) {
	    if ( l == 1 ) dp[h][h+l-1] = 0;
	    else {
		// (h~m), (m+1~h+l-1)
		int min_cost = INF;
		for ( int m = h; m < h + l - 1; m++ ) {
		    int cost = dp[h][m] + dp[m+1][h+l-1] + r[h] * c[m] * c[h+l-1];
		    min_cost = min( min_cost, cost );
		}
		dp[h][h+l-1] = min_cost;
	    }
	}
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}
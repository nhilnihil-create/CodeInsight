#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;

#define MAX_N (105)
#define MAX_W (10005)
int v[MAX_N];
int w[MAX_N];
int dp[2][MAX_W];

int main()
{
    int N, W;
    scanf("%d %d", &N, &W);
    memset( dp, 0, 2 * MAX_W );

    for ( int i = 0; i < N; i++ ) {
	scanf("%d %d", &v[i], &w[i]);
    }

    for ( int i = 0; i < N; i++ ) {
	for ( int j = 1; j <= W; j++ ) {
	    if ( j >= w[i] ) {
		dp[(i + 1)%2][j] = max( dp[i%2][j-w[i]] + v[i], max( dp[i%2][j], dp[(i+1)%2][j-1] ) );
	    }
	    else {
		dp[(i + 1)%2][j] = max( dp[i%2][j], dp[(i+1)%2][j-1] );
	    }
	}
    }
    
    printf("%d\n", dp[N%2][W]);
    return 0;
}
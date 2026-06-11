#include <stdio.h>
#define MAX_N (105)

int n;
int G[MAX_N + 1][MAX_N + 1];
int d[MAX_N + 1];		// ????????????
int f[MAX_N + 1];		// ????????????
int time;
int dfs(int cur)
{
    d[cur] = time;
    for ( int i = 1; i <= n; i++ ) {
	if ( G[cur][i] && (d[i] == 0)) {
	    time++;
	    dfs(i);
	}
    }
    time++;
    f[cur] = time;
}

int main()
{
    scanf("%d", &n);
    
    for ( int i = 0; i < n; i++ ) {
	int u, k;
	scanf("%d %d", &u, &k);
	for ( int j = 0; j < k; j++ ) {
	    int v;
	    scanf("%d", &v);
	    G[u][v] = 1;
	}
    }

    time = 0;

    for ( int i = 1; i <= n; i++ ) {
	if ( d[i] == 0 ) {
	    time++;
	    dfs(i);
	}
    }


    for ( int i = 1; i <= n; i++ ) {
	printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}
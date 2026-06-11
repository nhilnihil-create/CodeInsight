#include<cstdio>
#include<queue>
#define MAX 100
#define INF 1000
using namespace std;
int n, g[MAX][MAX], labels[MAX], d[MAX];
queue<int> Q;

void bfs(int s) {
    int v,u;
    labels[s] = 1;
    d[s]=0;
    Q.push(s);
    while (!Q.empty()) {
	u = Q.front(); Q.pop();
	for (v=0; v<n; v++) {
	    if (g[u][v] && labels[v]==0) {
		labels[v] =1;
		d[v] = d[u] +1;
		Q.push(v);
	    }
	}
	labels[u] = 2;
    }
}

int main() {
    int i,u,k,v,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    g[i][j]=0;
	}
    }

    for(i=0;i<n;i++){
	scanf("%d %d",&u, &k);
	for(j=0;j<k;j++){
	    scanf("%d",&v);
	    g[u-1][v-1]=1;
	}
    }

    for(i=0; i<n; i++) { labels[i]=0; d[i]=INF;}

    bfs(0);

    for(i=0; i<n; i++) {
	if (d[i] != INF) printf("%d %d\n", i+1, d[i]);
	else printf("%d -1\n", i+1);
    }
    return 0;
}
    
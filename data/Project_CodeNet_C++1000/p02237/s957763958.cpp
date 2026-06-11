#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n,u,k,v;
	int i,j;
	vector<vector<int> > V;
	scanf("%d",&n);
	V.resize(n);
	for(i=0; i<n; ++i) {
		V[i].resize(n);
		for(j=0; j<n; ++j) {
			V[i][j]=0;
		}
	}
	for(i=0; i<n; ++i) {
		scanf("%d%d",&u,&k);
		for(j=0; j<k; ++j) {
			scanf("%d",&v);
			V[u-1][v-1]=1;
		}
	}
	for(i=0; i<n; ++i) {
		for(j=0; j<n-1; ++j) {
			printf("%d ",V[i][j]);
		}
		printf("%d\n",V[i][n-1]);
	}
	return 0;
}
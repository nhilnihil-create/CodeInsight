/**
 * Bredth first search.
 * graphs could be circular.
 * there could be a better answer later.
 */

#include <iostream>
using namespace std;
const int N = 101;
int adj[N][N] = {0};
int d[N] = {0};

void bfs(int n, int dd) {
	int s[N] = {0}; // this needs to be a stack member.
	int k = adj[n][0];
//	cout << n << ' ' << dd << ' ' << k << endl;
	int kk = 0;
	for (int j=1;j<=k;j++) {
		int nn = adj[n][j];
		if (d[nn] != -1 && d[nn] <= dd) continue; // this condition is important.
		d[nn]=dd;
		s[kk++]=nn;
	//	cout << nn << endl;
	}

	for (int j=0;j<kk;j++)
	{
		bfs(s[j], dd+1);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		int j, k;
		cin >> j >> k;
		d[j]=-1;
		adj[j][0]=k;
		for (int m=1;m<=k;m++) {
			int a;
			cin >> a;
			adj[j][m]=a;
		}
	}

	d[1]=0;

	bfs(1, 1);

	for (int i=1;i<=n;i++){
		cout << i << ' ' << d[i] << endl;
	}

	return 0;
}
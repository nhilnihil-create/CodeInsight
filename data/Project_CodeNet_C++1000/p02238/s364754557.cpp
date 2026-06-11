#include <iostream>
using namespace std;

int visit[100],end[100],a[100][100];
int t,N,u,k,col;

void rist_to_mat(int N) {
	for(int l=0; l<N; ++l) {
		cin >> u >> k;
		for (int i=0; i<k; ++i) {
			cin >> col;
			a[u-1][col-1] = 1;
		}
	}
}

void dfs(int cur,int N) {
	t += 1;
	visit[cur] = t;
	for(int dst=0; dst<N; ++dst) {
		if(a[cur][dst] == 1 && visit[dst] == 0) {
			dfs(dst,N);
		}
	}
	t += 1;
	end[cur] = t;
}

int main() {
	cin >> N;
	rist_to_mat(N);
	for(int i=0; i<N; ++i) {
		if(visit[i] == 0) dfs(i,N);
	}
	for(int i=0; i<N; ++i) {
		cout << i+1 << ' ' << visit[i] << ' ' << end[i] << endl;
	}
}
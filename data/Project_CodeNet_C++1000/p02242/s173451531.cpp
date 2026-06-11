#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr int LEN = 105;
int a[LEN][LEN];

int dikstra(int g, const int n){
	int d[n];
	bool check[n] = {0};
	memset(d, 1, sizeof(d));
	d[0] = 0;

	while(true){
		int u;
		int min_cost = INT_MAX;
		rep(i, n){
			if(!check[i] && (d[i] < min_cost)) {
				min_cost = d[i];
				u = i;
			}
		}

		if(min_cost == INT_MAX) break;
		check[u] = true;

		rep(v, n){
			if(!check[v] && (a[u][v] > -1)){
				if((d[u] + a[u][v]) < d[v]){
					d[v] = d[u] + a[u][v];
				}
			}
		}
	}

	return d[g];
}

int main(){
	memset(a, -1, sizeof(a));
	int n; cin >> n;
	rep(i, n){
		int u, k; cin >> u >> k;
		rep(j, k){
			int v, c; cin >> v >> c;
			a[u][v] = c;
		}
	}

	rep(i, n) cout << i << ' ' << dikstra(i, n) << endl;

	return 0;
}


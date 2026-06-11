#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int BIG = 1e9 + 555;
const int maxN = 2000 + 555;

int n, m;
int s[maxN], t[maxN];

ll memo[maxN][maxN];
ll memop[maxN][maxN];

void update(int r){
	for(int i = 0; i <= m; i++){
		memop[r + 1][i + 1] = (memop[r + 1][i] + memo[r][i]) % MOD;
	}
	for(int i = 0; i <= m; i++){
		memop[r + 1][i + 1] = (memop[r][i + 1] + memop[r + 1][i + 1]) % MOD;
		//cerr << r + 1 << ' ' << i + 1 << ' ' << memop[r + 1][i + 1] << '\n';
	}
}

ll range(int x, int y, int u, int v){
	x++;	y++;	u++;	v++;
	return ((memop[u][v] - memop[x - 1][v] - memop[u][y - 1] + memop[x - 1][y - 1]) % MOD + MOD) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}

	for(int j = 1; j <= m; j++){
		cin >> t[j];
	}

	memo[0][0] = 1;
	update(0);
	
	ll fRes = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i] != t[j]){
				continue;
			}
			//for(int ii = 0; ii < i; ii++){
			//	for(int jj = 0; jj < j; jj++){
			//		memo[i][j] += memo[ii][jj];
			//	}
			//}
			memo[i][j] = range(0, 0, i - 1, j - 1);
			fRes = (fRes + memo[i][j]) % MOD;
		}

		update(i);
	}

	cout << (fRes + 1) % MOD << '\n';

	return 0;
}
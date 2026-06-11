#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> mat;
const ll mod = 2019;
const int MAXN = 1e5+5;

int used[MAXN][4], mark[MAXN], gen[MAXN];

queue<int> fila;
vector<int> g[MAXN];

void solve(int i, int t, int qtd) {
	if(used[i][t]) return;
	used[i][t] = 1;
	
	if(t == 0) {
		fila.push(i);
		gen[i] = qtd;
		return;
	}
	
	for(auto u : g[i])
		solve(u, t-1, qtd);
	return;
}

int main() {
	int n, m;
	memset(gen, -1, sizeof gen);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
	}
	int s, t;
	cin >> s >> t;
	fila.push(s);
	gen[s] = 0;
	
	while(!fila.empty()) {
		int atual = fila.front();
		fila.pop();
		if(!mark[atual]) {
			mark[atual] = 1;
			solve(atual, 3, gen[atual]+1);
		}
	}
	
	cout << gen[t] << endl;
	
}


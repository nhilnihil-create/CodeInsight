#include <bits/stdc++.h>

#define fst first
#define snd second
#define ll long long
#define ld long double
#define pb push_back
#define emp emplace_back
#define pii pair<int, int>
#define usg unsigned
#define sg signed
#define mp make_pair

using namespace std;

void setIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
}

const ld PI = 4*atan((ld)1);
const int INF = 1e9+7;
const ll _INF = 1e18+7;
const int mxn = 1e5+7;

int par[mxn], sz[mxn];

int fpar(int x){
	if (par[x] == x) return x;
	return par[x] = fpar(par[x]);
}

void join(int a, int b){
	a = fpar(a), b = fpar(b);
	if (a != b){
		if (a > b) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
		sz[b] = 0;
	}
}

int main(){
	setIO();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		join(a, b);
	}
	int cmp = 0;
	for (int i = 0; i < n; i++){
		if (sz[i]) cmp++;
	}
	cout << cmp-1 << endl;
}
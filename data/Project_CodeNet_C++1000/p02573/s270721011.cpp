#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define bug cout << "ok" << endl

const ll INF = 1e9 + 5, N = 2e5 + 5, mod = 1e9 + 7, M = 1e5 + 5;

int p[N], sz[N];

void make_set(int v){
	p[v] = v;
	sz[v] = 1;	
}

int find_set(int v){
	if(p[v] == v) return v;
	return p[v] = find_set(p[v]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) make_set(i);
	while(m--){
		int a, b;
		cin >> a >> b;
		union_set(a, b);
	}
	int mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, sz[i]);
	cout << mx << endl;
}
#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

vector<int> graph[250000];
bool besucht[250000];
ll query[250000];
ll res[250000];

void dfs( int p, ll sum ){
	if( besucht[p] ) return;
	besucht[p] = true;
	res[p] = sum;
	for( auto next : graph[p] ){
		dfs( next, sum+query[next] );
	}
}

int main(){
	int n, q; cin >> n >> q;
	for( int i = 0; i < n-1; ++i ){
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for( int i = 0; i < q; ++i ){
		int p; ll x; cin >> p >> x;
		query[p-1] += x;
	}
	dfs(0, query[0]);
	for( int i = 0; i < n; ++i ){
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}

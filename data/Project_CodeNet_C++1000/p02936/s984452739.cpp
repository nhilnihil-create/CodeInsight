#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const int maxn = 200010;
#define all(x) x.begin(),x.end()

#define ld long double

int n, q;
vector <int> adjlist[maxn];
int co[maxn];
int v[maxn];

void dfs(int x, int p) {
	v[x] += co[x];
	
	for (auto i: adjlist[x]) {
		if (i == p) continue;
		v[i] += v[x];
		dfs(i,x);
	}
}


int main() {
	cin >> n >> q;
	for (int i =0;i<n-1;i++) {
		int a,b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	for (int i =0;i<q;i++) {
		int x, v; cin >> x >> v;
		co[x] += v;
	}
	
	dfs(1,-1);
	for (int i =1;i<=n;i++) {
		cout << v[i] << " ";
	}
	
}


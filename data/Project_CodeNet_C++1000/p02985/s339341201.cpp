#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);
const int maxn = 100010;
const int mod = 1e9+7;

int n,k;
vector <int> adjlist[maxn];
int ans;

void mul(int &a, int b) {
	a *= b;
	a %= mod;
}

void dfs(int x, int p) {
	int co = (p == -1 ? 1 : 2);
	//~ cout << x << " " << co << "\n";
	for (auto i: adjlist[x]) {
		if (i == p) continue;
		mul(ans,k-co);
		co++;
		dfs(i,x);
	}
}

int32_t main() {
	cin >> n >> k;
	for (int i =0;i<n-1;i++) {
		int a,b; cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	ans = k;
	dfs(1,-1);
	cout << ans % mod;
}


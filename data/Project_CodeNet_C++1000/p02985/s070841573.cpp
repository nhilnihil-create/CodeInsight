#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


int n, k;
ll ans=1;

vector<int> g[maxn];

void dfs(int at, int p=0) {
    ll ch = g[at].size();
    if (ch>k) {
	//assert(0);
	ans=0;
    }
    ll cur=k-1-(p!=0);
    
    for (int to: g[at]) {
	if (to==p) continue;
	ans *= (cur--);
	ans %= mod;
    }
    
    for (int to: g[at]) {
	if (to == p) continue;
	dfs(to,at);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>k;
    for (int i=0; i<n-1; i++) {
	int u,v; cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
    }


    ans = k;//root
    dfs(1);

    out(ans);
    return 0;
}

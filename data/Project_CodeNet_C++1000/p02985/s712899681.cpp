#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2, MOD=1e9+7;
int N, K;
int a[MAX_N],b[MAX_N];
vector<int> G[MAX_N];
bool ok;

void add_edge(int from, int to)
{
	G[from].push_back(to);
	G[to].push_back(from);
}

ll dfs(int x, int par)
{
	int cnt = 0;
	ll res = 1LL;
	for(int i=0;i<G[x].size();++i){
	    int y = G[x][i];
	    if(y != par){
			ll choice = 1LL*(K-1-cnt-((x==1)?0:1));
			if(choice <= 0){
				ok = false;
				return 0;
			}
	        (res *= choice*dfs(y,x)%MOD)%=MOD;
	        cnt++;
	    }
	}
	return res;
}
 
void solve()
{
	for(int i=1;i<=N;++i)if((int)G[i].size()+1>K){
		cout << 0 << '\n';
		return;
	}
	ok = true;
	ll ans = 1LL*K*dfs(1,0)%MOD;
	if(!ok) cout << 0 << '\n';
	else cout << ans << '\n';
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N-1;++i){
		cin >> a[i] >> b[i];
		add_edge(a[i],b[i]);
	}
	solve();
	return 0;
}
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

ll N,K;
int p[maxn],c[maxn];
ll sc[maxn];
int fa[maxn],sz[maxn];
bool vis[maxn];
int id = 0;

void dfs(int x){
	fa[x] = id;
	sz[id] += 1;
	sc[id] += c[x];
	vis[x] = 1;
	int nx = p[x];
	if(!vis[nx]){
		dfs(nx);
	}
}
void solve(){
	for(int i = 1;i<=N;i++){
		if(!vis[i]){
			id++;
			dfs(i);
		}
	}
	ll ans = -2e18;
	for(int i = 1;i<=N;i++){
		int id = fa[i];
		ll cur = 0;
		ll k = K;
		if(k > sz[id]){
			if(sc[id] > 0){
				cur += (k/sz[id]-1) * sc[id];
			}
			k = k%sz[id] + sz[id];
		}
		for(int j = 1,nx = p[i];j<=k;j++,nx = p[nx]){
			cur += c[nx];
			ans = max(ans,cur);
		}
		
	}
	cout<<ans<<'\n';
}
int main(){
	// debug;
	ios;

	cin>>N>>K;
	for(int i = 1;i<=N;i++) cin>>p[i];
	for(int i = 1;i<=N;i++) cin>>c[i];
	solve();
	
	return 0;
}

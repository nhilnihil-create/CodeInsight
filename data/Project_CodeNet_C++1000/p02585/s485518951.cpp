//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

#define SZ 500005

vector<int>edge[SZ];
int up[20][SZ],dep[SZ];
struct dbling{
	bool ready = 0;
	void dfs(int v,int u,int d){
		up[0][v] = u; dep[v] = d;
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i], v, d+1);
		}
	}
	void prepare(){
	    dfs(1,-1,0);
		rep(j,19){
			rep(i,SZ){
				if(up[j][i] == -1) up[j+1][i] = up[j][i];
				else up[j+1][i] = up[j][up[j][i]];
			}
		}
		ready = 1;
	}
	int get(int a,int b){
		if(dep[a] > dep[b]) swap(a,b);
		int D = dep[b]-dep[a];
		rep(i,20){
			if(((D>>i)&1)) b = up[i][b];
		}
		if(a == b) return a;
		for(int i=19;i>=0;i--){
			if(up[i][a] != up[i][b]){
				a = up[i][a];
				b = up[i][b];
			}
		}
		return up[0][a];
	}
	int dist(int a,int b){
		int c = get(a,b);
		return dep[a]+dep[b]-2*dep[c];
	}
	int dist(int a,int b,int c){
		//assuming c is lca of (a,b)
		return dep[a]+dep[b]-2*dep[c];
	}
	int go_up(int v,int a){
	    if(dep[v] < a) return -1;
	    rep(i,20) if(((a>>i)&1)) v = up[i][v];
	    return v;
	}
	//a ---- b
	//と並べたときのx番目 (1-indexed)
	//存在しない場合は-1を返す
	//verified : opencup Warsaw I
	int v_on_path(int a,int b,int x){
		int c = get(a,b);
		int d = dist(a,b,c);
		if(x <= 0 || x > d+1) return -1;
		if(x <= dep[a]-dep[c]+1){
			return go_up(a, x-1);
		}
		else{
			x = d+2-x;
			return go_up(b, x-1);
		}
	}
}kaede;
struct uf{
	int par[SZ],ran[SZ], sz[SZ];
	void init(){ for(int i=0;i<SZ;i++) par[i] = i, ran[i] = 0, sz[i] = 1;}
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]){
			par[x] = y;
			sz[y] += sz[x];
		}
		else{
			par[y] = x;
			sz[x] += sz[y];
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}uf;
ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	else return gcd(b, a%b);
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[2000005],R[2000005];
void make(){
	F[0] = 1;
	for(int i=1;i<2000005;i++) F[i] = F[i-1]*i%mod;
	R[2000004] = modpow(F[2000004], mod-2);
	for(int i=2000003;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int g(ll v, int p){
	return ((v >> p)&1);
}



//木、UFは頂点数50万
//階乗系は200万
//modは10^9+7
//足りなかったり仕様と違ったら絶対に変更を忘れない！！


int n, p[5005], go[32][5005];
ll k;
ll c[5005], sum[32][5005], best[32][5005];
int main(){
	cin >> n >> k;
	repn(i, n) cin >> p[i];
	repn(i, n) cin >> c[i];
	repn(i, n){
		go[0][i] = p[i];
		sum[0][i] = c[i];
		best[0][i] = c[i];
	}
	rep(k, 30){
		repn(i, n){
			go[k+1][i] = go[k][go[k][i]];
			sum[k+1][i] = sum[k][i] + sum[k][go[k][i]];
			best[k+1][i] = max(best[k][i], sum[k][i]+max(0LL, best[k][go[k][i]]));
		}
	}
	ll ans = -1e18;
	repn(i, n){
		ll cur = 0;
		int ii = i;
		rep(x, 30){
			if(!((k>>x)&1)) continue;
			ans = max(ans, cur + best[x][ii]);
			cur += sum[x][ii];
			ii = go[x][ii];
		}
	}
	cout << ans << endl;
}
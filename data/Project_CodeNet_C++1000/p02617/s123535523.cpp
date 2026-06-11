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
struct UF{
	int par[2000005],ran[2000005];
	void init(){ for(int i=0;i<2000005;i++) par[i] = i, ran[i] = 0; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}uf;


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
int n;
vector<int>edge[200005];

void solve(){
	cin >> n;
	ll ans = 0;
	repn(i, n) ans += 1LL * i * (i+1) / 2;
	rep(i, n-1){
		int a, b; cin >> a >> b;
		ans -= 1LL * min(a, b) * (n+1-max(a, b));
	}
	cout << ans << endl;
}

int main(){
	uf.init();
	make();
	solve();
}
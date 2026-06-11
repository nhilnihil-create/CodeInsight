#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
const ll INF=1e18+7;
const ll MOD=1e9+7;
const ll N = 1007;
class UnionFind{
public:
	vector<int> par;
	//0-indexed
	void init(int n = 1) {
		par.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int root(int x = 1){
		if(par[x]==x)return x;
		else{
			return par[x] = root(par[x]);
		}
	}
	void unite(int x = 1,int y = 1){
		x = root(x);
		y = root(y);
		if(x==y)return;
		else par[x] = y;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	UnionFind uf;
	uf.init(n);
	FOR(i,0,m){
		ll x,y;
		cin>>x>>y;
		uf.unite(x,y);
	}
	ll q;
	cin>>q;
	FOR(i,0,q){
		ll x,y;
		cin>>x>>y;
		if(uf.root(x)==uf.root(y)){
			pri("yes");
		}else{
			pri("no");
		}
	}
}

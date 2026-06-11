#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
class UF{
public:
	vector<int> par,num;
	int find(int v){
		return (par[v]==v)? v: (par[v]=find(par[v]));
	}
	explicit UF(int N):par(N),num(N,1){
		iota(all(par),0);
	}
	void unite(int u,int v){
		u=find(u),v=find(v);
		if(u==v)return;
		if(num[u]<num[v])swap(u,v);
		num[u]+=num[v];
		par[v]=u;
	}
	bool same(int u,int v){
		return find(u)==find(v);
	}
	bool ispar(int v){
		return v=find(v);
	}
	int size(int v){
		return num[find(v)];
	}
};
int main(){
    int n,q;
    cin>>n>>q;
    UF uf(n);
    while(q--){
        int t,a,b;
        cin>>t>>a>>b;
        if(t){
            cout<<uf.same(a,b)<<"\n";
        }else{
            uf.unite(a,b);
        }
    }
}
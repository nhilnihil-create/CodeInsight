#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

struct UnionFind{
	vi par;		//par[i]:=(0以上の場合iの親, 0未満の場合はiを含むグループのサイズ).
	int num;	//num:=(グループの数).
	
	UnionFind(int n):par(n,-1),num(n){}//constructor.
	
	void init(){fill(ALL(par),-1), num=par.size();}
	int root(int x){return (par[x]<0)?x:par[x]=root(par[x]);}//recrusion.
	int size(int x){return -par[root(x)];}
	bool same(int x,int y){return root(x)==root(y);}
	bool unite(int x,int y){
		x=root(x), y=root(y);
		if(x==y) return false;//Do nothing.
		if(size(x)<size(y)) swap(x,y);//merge technique(y to x).
		par[x]+=par[y];
		par[y]=x;
		num--;
		return true;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	
	UnionFind ob(n);
	REP(i,q){
		int t,u,v;
		cin>>t>>u>>v;
		
		if(t==0) ob.unite(u,v);
		else cout<<(ob.same(u,v)?1:0)<<endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr long long inf = 3e18;
struct UnionFind{
	vector<int>par,size;
	int find(int x){
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	bool merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(size[x]>size[y])swap(x,y);
		par[x]=y;
		size[y]+=size[x];
		return true;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	UnionFind(int x):size(x,1),par(x){
		iota(all(par),0);
	}
};
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;cin>>N>>Q;
	UnionFind uf(N);
	while(Q--){
		int t,u,v;cin>>t>>u>>v;
		if(!t)uf.merge(u,v);
		else cout<<uf.same(u,v)<<"\n";
	}
}
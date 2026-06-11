#include <bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
struct UnionFind{
  int num;//連結成分の数
  vector<int> r,p;//そのグループのサイズ,自分の親っぽいやつ
  UnionFind(){}
  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}

  int find(int x){//どのグループに所属するか
    return (x==p[x]?x:p[x]=find(p[x]));//xがグループの名前と一致するまでxを親にする
  }

  bool same(int x,int y){//同じグループかどうか
    return find(x)==find(y);
  }

  void unite(int x,int y){//xとyを同じグループにする
    x=find(x);y=find(y);//xとyのグループの名前をどっちかが変える
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);//サイズが大きい方をxとする
    r[x]+=r[y];//yの親をxにする（今までyだったグループ名がxになる）
    p[y]=x;
    num--;
  }

  int size(int x){//グループの大きさ
    return r[find(x)];
  }

  int count() const{//グループの数
    return num;
  }
};
  //END CUT HERE

signed main(){
  int n,q;cin>>n>>q;
  UnionFind uf(n);
  while(q--){
    int t,u,v;cin>>t>>u>>v;
    if(t)cout<<uf.same(u,v)<<endl;
    else uf.unite(u,v);
  }
}

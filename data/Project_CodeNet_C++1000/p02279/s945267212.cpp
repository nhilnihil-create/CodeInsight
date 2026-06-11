#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define NIL -1

struct Node{int p,l,r;};
Node T[MAX];
int n,D[MAX];

void print(int u){
  int i,c;
  cout<<"node "<<u<<": parent = ";
  cout<<T[u].p<<", depth = ";
  cout<<D[u]<<", ";
  if(D[u]==0) cout<<"root";
  else if(T[u].l==NIL) cout<<"leaf";
  else cout<<"internal node";
  cout<<", [";
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) cout<<", ";
    cout<<c;
  }
  cout<<"]"<<endl;
}
  

int rec(int u,int p){
  D[u]=p;
  if(T[u].r!=NIL) rec(T[u].r,p);
  if(T[u].l!=NIL) rec(T[u].l,p+1);
}

int main() {
  int v,d,c,l,r;
  cin>>n;
  
  rep(i,n) T[i].p=T[i].l=T[i].r=NIL;
  
  rep(i,n){    
    cin>>v>>d;
    rep(j,d){
      cin>>c;
      if(j==0) T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
    }
  }
  rep(i,n){
    if(T[i].p==NIL) r=i;
  }
  
  rec(r,0);
  
  rep(i,n) print(i);
  
  return 0;
}

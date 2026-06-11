#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
const double EPS = 1e-10;//sample:if((double)>=(double)+EPS)
#define CLR(a) memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)  cerr << #x << " = " << (x) << endl;//debug
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

using namespace std;
#define NIL -1
#define MAX 100005
struct Node {int p,l,r;};
Node T[MAX];
int n,D[MAX];
void print(int u){
  cout<<"node "<<u<<": parent = "<<T[u].p<<", "<<"depth = "<<D[u]<<", ";
  if(T[u].p==NIL)cout<<"root, [";
  else if(T[u].l==NIL)cout<<"leaf, [";
  else cout<<"internal node, [";
  for(int i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i)cout<<", ";
    cout<<c;
  }
  cout<<"]"<<endl;
}
void rec(int u,int p){
  D[u]=p;
  if(T[u].r!=NIL)rec(T[u].r,p);
  if(T[u].l!=NIL)rec(T[u].l,p+1);
}
int main(){
  cin>>n;
  rep(i,n)T[i].p=T[i].l=T[i].r=NIL;
  int l=0;
  rep(i,n){
    int v,d;
    cin>>v>>d;
    rep(j,d){
      int c;
      cin>>c;
      if(!j)T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
    }
  }
  int r;
  rep(i,n)if(T[i].p==NIL)r=i;
  rec(r,0);
  rep(i,n)print(i);
  return 0;
}

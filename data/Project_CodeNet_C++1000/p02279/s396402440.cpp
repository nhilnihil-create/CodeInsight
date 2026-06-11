#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define MAX 100005


using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int NIL=-1;
struct node{
  int p,l,r;
};

 node T[MAX];
 int n,D[MAX];

 void print(int u){
   int i,c;
   cout<<"node "<<u<<": ";
   cout<<"parent = "<<T[u].p<<", ";
   cout<<"depth = "<<D[u]<<", ";

   if(T[u].p==NIL)cout<<"root, ";
   else if(T[u].l==NIL)cout<<"leaf, ";
   else cout<<"internal node, ";

   cout<<"[";

   for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
     if(i)cout<<", ";
     cout<<c;
   }
   cout<<"]"<<endl;
 }

int rec(int u,int p){
   D[u]=p;
   if(T[u].r!=NIL)rec(T[u].r,p);
   if(T[u].l!=NIL)rec(T[u].l,p+1);
 }

int main(){
  int d,v,c,l,r;
  cin>>n;
  for(int i=0;i<n;i++)T[i].p=T[i].l=T[i].r=NIL;

  for(int i=0;i<n;i++){
    cin>>v>>d;
    for(int j=0;j<d;j++){
      cin>>c;
      if(j==0)T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
      }
    }
    for(int i=0;i<n;i++){
      if(T[i].p==NIL)r=i;
    }
    rec(r, 0);
    for(int i=0;i<n;i++)print(i);

  return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
  int p,r,l;
}node;
node tree[100001];
int n,d[100001];

//出力する関数
int print(int u){
  int i,c;
  cout<<"node "<<u<<": ";
  cout<<"parent = "<<tree[u].p<<", ";
  cout<<"depth = "<<d[u]<<", ";
  if(tree[u].p==-1) cout<<"root, ";
    else if(tree[u].l==-1) cout<<"leaf, ";
    else cout<<"internal node, ";
  cout<<"[";
  for(i=0,c=tree[u].l;c!=-1;++i,c=tree[c].r){
    if(i) cout<<", ";
    cout<<c;
  }
  cout<<"]"<<endl;
}

//深さを求める
int rec(int u,int p){
  d[u]=p;
  if(tree[u].r!=-1) rec(tree[u].r,p);
  if(tree[u].l!=-1) rec(tree[u].l,p+1);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int i,j,d,v,c,l,r;
  cin>>n;
  memset(tree,-1,sizeof(tree));

  //ノードの情報を入力
  for(int i=0;i<n;++i){
    cin>>v>>d;    //v=ノードの番号(親ではない),d=次数
    for(int j=0;j<d;++j){
      cin>>c;
      if(j==0) tree[v].l=c;
      else tree[l].r=c;
      l=c;
      tree[c].p=v;
    }
  }

  //
  for(int i=0;i<n;++i){
    if(tree[i].p==-1) r=i;
  }
  //
  rec(r,0);
  
  //出力
  for(i=0;i<n;++i) print(i);
  
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int>p;//ノードxの親
vector<int>rank;//ノードxの高さ

void shokika(int size){
  rank.resize(size,0);
  p.resize(size,0);
  for(int i=0;i<size;i++){
    p[i]=i;
    rank[i]=0;
  }
}

int find(int x){//代表
  if(x==p[x])
    return x;
  return p[x]=find(p[x]);//一回でいけるように//経路圧縮
}

int same(int x,int y){//xとyの一致
  if(find(x)==find(y))   //代表が同じ
    return 1;
  else
    return 0;
}

void unite(int x,int y){//ｘとyの合併
  x=find(x);//xの代表
  y=find(y);//yの代表

  if(rank[x]>rank[y])
    p[y]=x;//親を変える
  else
    p[x]=y;//親を変える

  if(rank[x]==rank[y])
    rank[y]++;//　rank[y]=rank[x]+1;
}


int main(){
  int n,a,b,q;
  int t;
  cin>>n>>q;

  shokika(n);

  for(int i=0;i<q;i++){
    cin>>t>>a>>b;
    if(t==0) unite(a,b);
    else if(t==1) {
      if(same(a,b)) cout<<1<<endl;
      else cout<<0<<endl;
    }
  }
  return 0;
}


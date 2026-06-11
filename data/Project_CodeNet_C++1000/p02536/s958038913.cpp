#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()
#define N 100001
int *par;
int *rrank;

int root(int x){
  if(par[x]==x)return x;
  else return par[x]=root(par[x]);
}

void init(int n){
  for(int i=0; i <= n; i++){
    par[i]=i;
    rrank[i]=0;
  }
}
bool same(int x,int y){
  return root(x)==root(y);
}

void link(int x,int y){
  int xx,yy;
  xx=root(x);
  yy=root(y);
  if(xx==yy)return;

  if(rrank[xx]<rrank[yy]) par[xx]=yy;
  else if(rrank[xx]>rrank[yy]){
    par[yy]=xx;
  }else{
    par[yy]=xx;
    rrank[xx]++;
  }
  return;
}

int main(){ 
  int n,m,a,b;
  cin>>n>>m;
  int ans=n-1;
  par=new int[n+1];
  rrank=new int[n+1];

  init(n);

  for (int i = 0; i < m; i++){
    cin >> a>>b;
    if(!same(a,b)){
      link(a,b);
      ans--;
    }
  }
  cout << ans <<endl;
  return 0;
}
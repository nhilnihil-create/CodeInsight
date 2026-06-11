#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
int ans[530][530];
int N,k=1;
int line(int u,int v,int color){
  u%=k;v%=k;
  if(u>v)swap(u,v);
  if(ans[u][v])return -1;
  ans[u][v]=color;return 0;
}
void f(int s,int M,int d,int cnt){
  for(int j=1;j<=M/2;j+=2){
    for(int i=0;i<k;i+=d){
      if(j==M/2&&i==k/2)break;
      if(line(s+i,s+i+j*d,cnt)<0)return;
    }
  }
  if(M==2){
    line(s+d/2,s+3*d/2,cnt);
    return;
  }
  for(int i=0;i<2;i++)f(s+i*d,M/2,d*2,cnt+1);
}
//main
signed main(){
  cin>>N;
  while(k<N)k<<=1;
  f(0,k,1,1);
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++)cout<<ans[i][j]<<" ";cout<<endl;
  }
}

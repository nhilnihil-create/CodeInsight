#include <bits/stdc++.h>
using namespace std;
#define int long long
//template
int ans[530][530];
int N,k=1;
int line(int u,int v,int level){
  u%=k;v%=k;
  if(u>v)swap(u,v);
  if(ans[u][v])return -1;
  ans[u][v]=level;return 0;
}
void f(int s,int M,int d,int cnt){
  if(M==1)return;
  for(int j=1;j<=M/2;j+=2)
    for(int i=0;i<k;i+=d)
      if(line(s+i,s+i+j*d,cnt)<0)return;
  f(s,M/2,d*2,cnt+1);
  f(s+d,M/2,d*2,cnt+1);
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

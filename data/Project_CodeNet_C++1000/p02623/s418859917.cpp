#include <bits/stdc++.h>
using namespace std;

#define int long long
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n,m,k;cin>>n>>m>>k;
  vector<int> a(n),b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  int now=0,nowtime=0;
  while(now<m&&nowtime+b[now]<=k)nowtime+=b[now++];
  int ans=now;
  for(int i=0;i<n;i++){
    nowtime+=a[i];
    while(now&&nowtime>k)nowtime-=b[--now];
    if(nowtime<=k)chmax(ans,i+1+now);
  }
  cout<<ans<<endl;
}

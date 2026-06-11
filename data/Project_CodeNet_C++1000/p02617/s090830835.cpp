#include <bits/stdc++.h>
using namespace std;

/*
f(L,R)=R-L+1-{i|L<=u[i],v[i]<=R}
つまり、長さの方は1がn,2がn-1,3がn-2,...だから合計でi*(n-i-1)のiが1~n
u[i],v[i]の方はu[i]<v[i]として、1-indexedでu[i]*(n-v[i]+1)
*/
#define int long long

signed main(){
  int n,ans=0;cin>>n;
  for(int i=0;i<n;i++)ans+=(i+1)*(n-i);
  for(int i=1;i<n;i++){
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    ans-=u*(n-v+1);
  }
  cout<<ans<<endl;
}

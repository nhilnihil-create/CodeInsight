#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,l;cin>>n>>l;
  int cnt=0;
  for(int i=1;i<=n;i++){
    int a=i+l-1;
    cnt+=a;
  }
  int ans=1e9;
   for(int i=1;i<=n;i++){
    int a=i+l-1;
     int t=cnt-a;
       if(abs(cnt-t)<abs(ans-cnt))ans=t;
   }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  vector<pair<int,int>> a[20];
  rep(i,n){
    int A; cin>>A;
    rep(j,A){
      int x,y; cin>>x>>y;
      x--;
      a[i].push_back(make_pair(x,y));
    }
  }
  int ans=0;
  for(int i=0; i<(1<<n); i++){
    bool ok=true;
    int honest_cnt=0;
    rep(j,n){
      if((i>>j)&1){
        honest_cnt++;
        for(auto x : a[j]){
          if(x.second==1 && !((i>>x.first)&1)) ok=false;
          if(x.second==0 &&  ((i>>x.first)&1)) ok=false;
        }
      }
    }
    if(ok) ans=max(honest_cnt,ans);
  }
  cout<<ans<<endl;
}

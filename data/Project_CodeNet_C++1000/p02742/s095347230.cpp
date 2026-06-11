#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
int main(){
  ll h,w;
  cin >> h >> w;
  ll ans=0;
  if(h==1 || w==1){
    cout << 1;
    return 0;
  }
  if(w%2==0){
    rep(i,h){
      ans+=w/2;
    }
  }else{
    rep(i,h){
      if(i%2==0){
        ans+=(w+1)/2;
      }else{
        ans+=w/2;
      }
    }
  }
  cout << ans;
}
    
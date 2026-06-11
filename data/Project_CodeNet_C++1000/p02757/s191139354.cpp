#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,P;
  cin>>N>>P;
  string s;
  cin>>s;
  ll ans(0);
  if(P == 2 || P == 5) {
    for(int i(0);i<N;i++){
      if((s[i]-'0') % P == 0){
        ans += i+1;
      }
    }
  }else{
    ll cnt[100000] = {0};
    cnt[0] = 1;
    int amari = 0;
    int ten(1);
    for(int i(N-1);i>=0;i--){
      amari += (s[i]-'0')*ten;
      amari %= P;
      cnt[amari]++;
      ten *= 10;ten%=P;
    }
    // for(int i(0);i<N;i++){
    //   if(s[i]-'0' == P) ans++;
    // }
    //cnt[amari]++;
    for(int i(0);i<P;i++){
      //cout << cnt[i] << endl;
      ans += (cnt[i]-1)*(cnt[i])/2;
    }
  }
  cout << ans << endl;
  return 0;
}

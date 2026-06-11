#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  ll ans = 0;
  for(int i=0; i<n; ++i){
    int bcnt = 0, acnt = 0;
    for(int j=0; j<n; ++j){
      if(an[i] > an[j]){
        if(i>j) ++bcnt;
        else ++acnt;
      }
    }
    ans += (ll)k *(k-1)/2 %MOD *(acnt +bcnt);
    ans += (ll)k *acnt;
    ans %= MOD;
  }
  cout << ans << endl;
}
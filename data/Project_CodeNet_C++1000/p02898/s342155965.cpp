#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll; 
int main() {
  ll n, k;cin>>n>>k;
  ll cnt=0;
  rep(i, n) {
    ll h;cin>>h;
    if(h>=k) cnt++;
  }
  cout << cnt;
}
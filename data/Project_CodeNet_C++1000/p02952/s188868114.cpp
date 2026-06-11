#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n; cin>>n;
  ll cnt=0;
  
  for(ll i=1; i<=n; i++) {
    ll d=floor(log10(i)+1);
    if(d%2==1) cnt++;
  }
  
  cout << cnt;
    
}
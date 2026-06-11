#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

ll pow( ll n ){
  return n*n;
}

ll func( ll n ){
  if( n == 0 ) return 1;
  if( n == 1 ) return 5;
  if( n%2 == 0 ) return pow(func(n/2));
  else return pow(func(n/2))*5;
}

int main() {
  ll n;cin >> n;

  if( n%2 == 1 ){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;

  ll cnt = 1;
  while( n >= func(cnt) ){
    ans += n/func(cnt)/2;
    ++cnt;
  }
  cout << ans << endl;
  return 0;
}

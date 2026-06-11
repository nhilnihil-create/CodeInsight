#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main() {
  ll l,r; cin>>l>>r;
  ll ans = 3000;
  for (ll i=l; i<=r-1; i++){
    for (ll j=i+1; j<=r; j++){
      if ((i*j) % 2019 == 0){
        cout << 0 << endl;
        return 0;
      }
      ans = min(ans, (i*j)%2019);
    }
  }
  cout << ans << endl;
}


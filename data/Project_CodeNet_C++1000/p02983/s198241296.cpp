#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  ll L,R; cin >>L >>R;
  ll ans=pow(10,9);
  for (ll i=L;i<R;i++) {
    for (ll j=i+1;j<=R;j++) {
      ll a=(i*j)%2019;
      if (a==0) {
        cout <<0 <<endl;
        return 0;
      }
      ans=min(ans,a);
    }
  }
  cout <<ans <<endl;
  return 0;
}

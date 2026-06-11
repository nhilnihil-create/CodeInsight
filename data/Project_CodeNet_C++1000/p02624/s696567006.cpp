#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n+1,1);
  rep(i,2,n+1){
    for(int j=i; j<n+1; j+=i){
      a[j]++;
    }
  }
  ll ans=1;
  rep(i,2,n+1){
    ans= ans + a[i]*i;
  }
  cout << ans << endl;
  return 0;
}
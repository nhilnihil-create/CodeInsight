#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

ll gcd(ll x, ll y){
  if(x%y==0) return y;
  return gcd(y, x%y); 
}

int main(){
  int n; cin >> n;
  vector<ll> v(n);
  map<ll, ll> cnt;
  for(int i=0; i<n; i++){
    cin >> v.at(i);
    cnt[v[i]] += 1;
  }
  ll ans=0, num=1;
  if(cnt[0]==1 && v[0]==0){
    ans = 1;
    for(int i=1; num<n; i++){
      for(int j=0; j<cnt[i]; j++){
        ans *= cnt[i-1];
        ans %= 998244353;
      }
      
      if(ans==0) break;
      num += cnt[i];
    }
  }
  //for(int i=0; i<n; i++) cout << cnt[i] << endl;
  cout << ans << endl;
}
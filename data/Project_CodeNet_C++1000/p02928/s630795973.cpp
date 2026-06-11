#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(a[i] == a[j]) continue;
      else if(a[i] < a[j]) ans += k*(k-1)/2;
      else ans += k*(k+1)/2;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
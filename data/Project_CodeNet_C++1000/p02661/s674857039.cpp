#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll ans = 0;
  if(n % 2 == 0){
    ll ma = a[n / 2 - 1] + a[n / 2], mb = b[n / 2 - 1] + b[n / 2];
    ans = mb - ma + 1;
  }
  else{
    ll ma = a[n / 2], mb = b[n / 2];
    ans = mb - ma + 1;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}

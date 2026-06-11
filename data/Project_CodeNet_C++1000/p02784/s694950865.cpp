#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll h,n;
  cin >> h >> n;
  ll sum=0;
  for(ll i=0;i<n;i++){
    ll a;
    cin >> a;
    sum+=a;
  }
  if(sum>=h) cout << "Yes" << endl;
  else cout << "No" << endl;
}
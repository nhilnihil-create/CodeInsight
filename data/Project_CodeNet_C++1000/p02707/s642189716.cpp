#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;
const double pi=3.14159265;

int main() {
  ll n;
  cin >> n;
  vector<ll>ans(n);
  rep(i,n-1){
    ll a;
    cin >> a;
    ans[a-1]++;
  }
  rep(i,n){
    cout << ans[i] << endl;
  }
  return 0;
 
}
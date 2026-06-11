#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll k,n;
  cin >> k >> n;
  vector<ll>a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll m=0;
  rep(i,n-1){
    m=max(m,a[i+1]-a[i]);
  }
  m=max(m,k-a[n-1]+a[0]);
  cout << k-m << endl;
  return 0;

}

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  ll n;
  ll a[81];
  cin >> n;
  rep(i,n) cin >> a[i];

  ll m = 1000;
  rep(i,n-1) {
    ll s = 0;
    if(a[i] < a[i+1]) {
      s = m/a[i];
      m += (a[i+1]-a[i])*s;
    }
  }
  cout << m << endl;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll m = 1000;
  rep(i,n){
    if(i+1 > n-1) continue;
    if(a[i+1]>a[i]){
      ll s = m/a[i];
      m -= s*a[i];
      m += s*a[i+1];
    }
  }
  cout << m << endl;
}

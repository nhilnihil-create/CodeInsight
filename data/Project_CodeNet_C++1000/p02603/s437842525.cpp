#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll m = 1000,n;
  cin >> n;
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  ll k = 0,p = 0;
  rep(i,0,n-1){
    m += k*a[i];
    k = 0;
    p = 0;
    if(a[i] < a[i+1]){
      k = m/a[i];
      p = a[i];
      m -= k*p;
    }
  }
  m += k*a[n-1];
  cout << m << endl;
}
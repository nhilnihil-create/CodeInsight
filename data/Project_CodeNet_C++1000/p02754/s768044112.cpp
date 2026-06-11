#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  ll n, a, b; cin >> n >> a >> b;
  if(a == b && a == 0) cout << 0 << endl;
  else{
    ll x = n/(a+b);
    cout << a*x + min(a,n-(x*(a+b))) << endl;
  }
}

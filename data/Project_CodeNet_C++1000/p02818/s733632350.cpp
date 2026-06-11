#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll a, b, k; cin >> a >> b >> k;

  if(k > a+b) cout << "0 0" << endl;
  else if(k > a) cout << "0 " << b-k+a << endl;
  else cout << a-k << " " << b << endl;
}

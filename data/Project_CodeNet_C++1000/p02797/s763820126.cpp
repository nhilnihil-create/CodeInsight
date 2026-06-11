#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n, k, s;
  cin >> n >> k >> s;  

  rep(i,k){
    cout << s << endl;
  }
  rep(i,n-k){
    if (s==1e9) cout << 1 << endl;
    else cout << s+1 << endl;
  }

  return 0;
}

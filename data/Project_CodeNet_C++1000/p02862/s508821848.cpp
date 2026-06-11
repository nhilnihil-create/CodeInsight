#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> comb(int N, int mod) {
  N++;
  bitset<30> modbit = mod-2;
  vector<int> comb(N+1, 1);
  rep(i, N) {
    comb[i+1] = (comb[i]*(N-1-i))%mod;
    int x = i+1;
    rep(j, 30) {
      if(j > 0) x *= x;
      x %= mod;
      if(modbit.test(j)) {
        comb[i+1] *= x;
        comb[i+1] %= mod;
      }
    }
  }
  return comb;
}

signed main() {
  int X, Y; cin >> X >> Y;
  if(X < Y) swap(X, Y);
  const int mod = 1000000007;
  
  if(X - Y > Y || (Y - (X-Y))%3 != 0) cout << 0 << endl;
  else {
    int a = X-Y+(Y - (X-Y))/3, b = (Y - (X-Y))/3;
    vector<int> c = comb(a+b, mod);
    cout << c[a] << endl;
  }
    
  
}
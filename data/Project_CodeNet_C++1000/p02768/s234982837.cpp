#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> comb(int N, int mod, int b) {
  N++;
  bitset<30> modbit = mod-2;
  vector<int> comb(b+3, 1);
  rep(i, b+2) {
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

int power(int n, int N, int mod) {
  if(N == 0) return 1;
  if(N == 1) return n;
  int a = power(n, N/2, mod);
  if(N%2 == 0) return (a*a)%mod;
  else return (a*a*n)%mod;
}

signed main() {
  int n, a, b; cin >> n >> a >> b;
  const int mod = 1000000007;
  
  if(n == 2) {
    if(a == 1 && b == 1) cout << 1 << endl;
    else if(a == 2 && b == 2) cout << 2 << endl;
    else cout << 0 << endl;
    return 0;
  }
  
  int ans = power(2, n, mod);
  vector<int> c = comb(n, mod, b);
  
  cout << ((ans-1-c[a]-c[b])%mod+mod)%mod << endl;
    
  
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  char d = 'a';
  rep(i,n) {
    char c;
    cin >> c;
    if(c==d) ans++;
    d = c;
  }
  cout << min(n-1,ans+2*k) << endl;
  return 0;
}
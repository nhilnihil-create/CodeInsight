//一度提出してます
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int64_t n,k,s;
  cin >> n >> k >> s;
  rep(i,k) cout << s << " ";
  if(s==1000000000) rep(i,n-k) cout << 3 << " ";
  else rep(i,n-k) cout << s+1 << " ";
  cout << endl;

}

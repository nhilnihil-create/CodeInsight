#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  ll int a, b, k;
  cin >> a >> b >> k;
  if(a > k) cout << a-k << " " << b << endl;
  else if(a+b < k) cout << 0 << " " << 0 << endl;
  else cout << 0 << " " << b-(k-a) << endl;
  return 0;
}

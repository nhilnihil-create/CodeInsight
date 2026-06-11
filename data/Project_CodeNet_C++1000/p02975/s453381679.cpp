#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll a[N];
  ll XOR = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    XOR ^= a[i];
  }
  bool can = true;
  if (XOR != 0) {
    can = false;
  }
  
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
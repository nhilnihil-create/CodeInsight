#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  vector<int> v(n);
  for(int i = 1;i <= n;i++) {
    cin >> a;
    v[a-1] = i;
  }
  for(auto x : v) cout << x << " ";
}
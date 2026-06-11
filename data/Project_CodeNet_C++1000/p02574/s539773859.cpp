#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  int g = 0;
  vector<int> fre(1e6+50, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    fre[x]++;
    g = __gcd(g, x);
  }

  if (g != 1) {
    cout << "not coprime\n";
    return 0;
  }
    
  int flag = 1;
  for (int i = 2; i < 1e6+50; ++i) {
    for (int j = 2*i; j < 1e6+50; j += i) {
      fre[i] += fre[j];
    }
    if (fre[i] >= 2) flag = 0;
  }

  if (flag) cout << "pairwise coprime\n";
  else cout << "setwise coprime\n";
}

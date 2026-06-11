#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  int n; cin >> n;
  cout << (n + max(h, w) - 1) / max(h, w) << "\n";
  return 0;
}

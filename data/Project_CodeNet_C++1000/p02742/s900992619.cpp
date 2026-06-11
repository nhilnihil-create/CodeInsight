#include <bits/stdc++.h>
using namespace std;

long long H, W;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> H >> W;
  if(H == 1 || W == 1) cout << "1\n";
  else cout << ((H * W) - 1) / 2 + 1 << "\n";
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min(ll a, ll b) {
  return a > b ? b : a;
}

ll max(ll a, ll b) {
  return a < b ? b : a;
}

int main() {
  int N;
  
  ll maxZ = -9223372036854775807l, minZ = 9223372036854775807l,
     maxW = -9223372036854775807l, minW = 9223372036854775807l;
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    ll in_x, in_y;
    
    cin >> in_x >> in_y;
    
    minZ = min(minZ, in_x + in_y);
    maxZ = max(maxZ, in_x + in_y);
    minW = min(minW, in_x - in_y);
    maxW = max(maxW, in_x - in_y);
  }
  
  cout << max(maxZ - minZ, maxW - minW) << endl;
  
  return 0;
}
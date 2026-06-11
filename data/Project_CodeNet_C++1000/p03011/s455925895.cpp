#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  cout << P + Q + R - max(P, max(Q, R)) << endl;
}
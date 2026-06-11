#include <bits/stdc++.h>
using namespace std;

// probably some shit cancels out 
// Sa0 = a1 ^ a2 ^ a3...
// Sa1 = a0 ^ a2 ^ a3...
// Sa2 = a0 ^ a1 ^ a3...
// Sa3 = a0 ^ a1 ^ a2...

// a0 ^ a1 

// a2 ^ a3


// Sa1 = a0 ^ a2 ^ a3 ^ a4 ...
// Sa2 = a0 ^ a1 ^ a3 ^ a4 ...
// Sa3 = a0 ^ a1 ^ a2 ^ a4 ...


// Sa0 ^ Sa1 = a0 ^ a1
// Sa1 ^ Sa2 = a1 ^ a2
// Sa2 ^ Sa3 = a2 ^ a3


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int all = 0;
  for (int i = 0; i < n; i += 2)
    all ^= a[i] ^ a[i + 1];
  for (int i = 0; i < n; i++) 
    cout << (all ^ a[i]) << ' ';
  return 0;
}
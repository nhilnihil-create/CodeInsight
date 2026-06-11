#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
  
  ll A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  ll d = abs(A-B);

  if (V <= W) {
    cout << "NO" << endl;
  }
  else if (d <= (V-W)*T) {
    cout << "YES" << endl;
  }
  else  cout << "NO" << endl;
}
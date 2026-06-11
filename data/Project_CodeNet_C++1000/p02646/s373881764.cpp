#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
  ll A, B, V, W, T;
  cin >> A >> V >> B >> W >> T;
  
  if (W >= V) {
    cout << "NO" << endl;
    return 0;
  }
  
  ll dist = abs(A- B);
  
  if ((V-W) * T >= dist) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A, V, B, W, T;
  cin >> A >> V >> B >> W >>T;
  long long D1 = abs(A-B);
  long long D2 = (V-W)*T;
    
  if(D1 <= D2) cout << "YES" << endl;
  else cout << "NO" << endl;
}
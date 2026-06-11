#include<bits/stdc++.h>
using namespace std;

signed main() {
  string S,T; cin >> S >> T;
  cout << (int)(S[0]==T[0]) + (int)(S[1]==T[1]) + (int)(S[2]==T[2]) << endl;
}

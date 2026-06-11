#include <bits/stdc++.h>
using namespace std;

int main() {
  int Hs, Ms, Hg, Mg, K;
  cin >> Hs >> Ms >> Hg >> Mg >> K;
  
  int S, G;
  S = 60 * Hs + Ms;
  G = 60 * Hg + Mg;
  
  cout << G - K - S << endl;
  
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  if(S.at(n-1) != 's') S += "s";
  else S += "es";
  cout << S << endl;  
}
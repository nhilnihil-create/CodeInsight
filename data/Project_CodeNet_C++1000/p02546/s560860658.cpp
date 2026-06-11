#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  if(S.at(S.size()-1)=='s') cout << S << "es\n";
  else cout << S << "s\n";
  return 0;
}
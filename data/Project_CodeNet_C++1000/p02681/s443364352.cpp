#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S, T;
  cin >> S >> T;
  
  if(T.compare(0,S.size(), S)) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  string ans = "No";
  if(S.at(2)==S.at(3) && S.at(4)==S.at(5)) ans = "Yes";
  cout << ans << endl;
  return 0;
}
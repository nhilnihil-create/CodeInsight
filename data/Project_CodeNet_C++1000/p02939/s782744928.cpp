#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S, memo; // 直前に取り出した文字列
  cin >> S;
  memo = S.substr(0, 1);
  int ans = 1;
  for (int i=1; i<S.size(); i++) {
    string sub = S.substr(i, 1);
    if (sub==memo&&i<S.size()-1) {
      memo = S.substr(i, 2);
      ans++;
      i++;
    }
    else if (sub==memo&&i==S.size()-1) break;
    else {
      memo = S.substr(i, 1);
      ans++;
    }
  }
  cout << ans << endl;
}
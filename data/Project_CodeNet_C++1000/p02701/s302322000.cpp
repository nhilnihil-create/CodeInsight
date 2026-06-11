#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  set<string> s;
  rep(i, n) {
    string S;
    cin >> S;
    s.insert(S);
  }
  cout << s.size() << endl;
  return 0;
}
      
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  set<string> s;
  int cnt = 0;
  rep(i, n) {
    string S;
    cin >> S;
    if(s.count(S) == 0) {
      s.insert(S);
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
      
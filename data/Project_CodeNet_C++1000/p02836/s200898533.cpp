 #include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  string tmp = s;
  reverse(s.begin(), s.end());
  int cnt = 0;
  rep(i, s.size()) {
    if(tmp.at(i) != s.at(i)) cnt++;
  }
  cout << cnt/2 << endl;
  return 0;
}
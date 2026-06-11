 #include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  rep(i, n) {
    cout << s.at(i) << t.at(i);
  }
  cout << endl;
  return 0;
}
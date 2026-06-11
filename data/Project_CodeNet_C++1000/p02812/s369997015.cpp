#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, n) {
    if(i >= n - 2) break;
    if(s.at(i) == 'A' && s.at(i+1) == 'B' && s.at(i+2) == 'C') cnt++;
  }
  cout << cnt << endl;
  return 0;
}
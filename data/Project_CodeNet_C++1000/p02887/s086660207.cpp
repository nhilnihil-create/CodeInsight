#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 1;
  rep(i,n-1) {
    if (s.at(i) != s.at(i+1)) cnt++;
  }
  cout << cnt << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
  }
  for(int i = 1; i < n - 1; i++) {
    if(a.at(i-1) < a.at(i) && a.at(i) < a.at(i + 1)) cnt++;
    else if(a.at(i-1) > a.at(i) && a.at(i) > a.at(i + 1)) cnt++;
  }
  cout << cnt << endl;
}

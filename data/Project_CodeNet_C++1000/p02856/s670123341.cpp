#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin>>m;
  pair<int, int> conv[10];
  for (int i=1; i<10; i++) {
    conv[i].first = 0;
    int j;
    for (j=1; j<=10; j++) {
      if (i * j >= 10) {
        break;
      }
      ++conv[i].first;
    }
    conv[i].second = 1 + (i * j) % 10;
    ++conv[i].first;
  }
  long long ans = 0;
  vector<int> rest;
  for (int i=0; i<m; i++) {
    int d;
    long long c;
    cin>>d>>c;
    if (d == 0) {
      ans += c - 1;
      rest.push_back(0);
      continue;
    }
    while (c > 0) {
      long long cnt = c / conv[d].first;
      long long mod = c % conv[d].first;
      ans += cnt * conv[d].first;
      for (int j=0; j<mod; j++) {
        rest.push_back(d);
      }
      c = cnt;
      d = conv[d].second;
      if (d == 0) {
        ans += c - 1;
        rest.push_back(0);
        break;
      }
    }
  }
  if (rest.size() <= 1) {
    cout<<ans<<endl;
    return 0;
  }
  int i = 1;
  int sum = rest[0];
  for (int i=1; i < rest.size(); i++) {
    sum += rest[i];
    ++ans;
    if (sum >= 10) {
      sum = 1 + sum % 10;
      ++ans;
    }
  }
  cout<<ans<<endl;
}
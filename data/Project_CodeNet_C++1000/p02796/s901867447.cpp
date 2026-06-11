#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int INF = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    int x,l;
    cin >> x >> l;

    int left = x - l;
    int right = x + l;
    a[i].first = right;
    a[i].second = left;
  }

  sort(a.begin(),a.end());
  int answer = 0;
  int last = -INF;

  for (int i = 0; i < n; i++) {
    int left = a[i].second;
    int right = a[i].first;

    if(left >= last) {
      answer++;
      last = right;
    }
  }

  cout << answer << '\n';

  return 0;
}

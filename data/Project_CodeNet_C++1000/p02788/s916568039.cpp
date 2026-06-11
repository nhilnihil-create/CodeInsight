#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, a;
  cin>>n>>d>>a;

  pair<int, int> xh[n];
  for (int i=0; i<n; i++) cin>>xh[i].first>>xh[i].second;
  sort(xh, xh + n);

  queue<pair<long long, long long>> q;

  long long sum = 0;
  long long cnt = 0;
  for (int i=0; i<n; i++) {
    while (!q.empty()) {
      auto front = q.front();
      if (xh[i].first <= front.first + d) {
        break;
      }
      sum -= front.second;
      q.pop();
    }
    if (sum >= xh[i].second) {
      continue;
    }
    long long tmp_cnt = ((xh[i].second - sum) - 1) / a  + 1;
    long long damage = tmp_cnt * a;
    q.push(make_pair(d + xh[i].first, damage));
    cnt += tmp_cnt;
    sum += damage;
  }
  cout<<cnt<<endl;
}
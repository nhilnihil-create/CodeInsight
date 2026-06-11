#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

constexpr long long INFLL = 1e18;

using namespace std;
using ll = long long;
using P = pair<int, int>;

ll solve(int temp, int end, vector<int> c, vector<int> p, int now) {
  vector<ll> ans;
  ll score = 0;

  while (temp >= end) {
    // cout << temp << endl;
    now = p.at(now);
    // cout << "now" << now << endl;
    score += c.at(now);
    ans.push_back(score);

    temp--;
  }
  // cout << "関数ない while終わり" << endl;
  ll maxS = ans.at(0);
  for (int i = 0; i < ans.size(); i++) {
    if (maxS < ans.at(i)) {
      maxS = ans.at(i);
    }
  }
  return maxS;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> c(n);
  int pT;
  for (int i = 0; i < n; i++) {
    cin >> pT;
    p.at(i) = pT - 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> c.at(i);
  }

  int now;
  ll ans = -1e18;
  for (int i = 0; i < n; i++) {
    now = i;
    vector<int> temp;
    temp.push_back(now);
    ll score = c.at(now);
    for (int j = 0; j < k; j++) {
      now = p.at(now);
      if (now == i) {
        break;
      }
      score += c.at(now);
      temp.push_back(now);
    }

    ll tempS = 0;
    for (int j = 0; j < temp.size(); j++) {
      tempS += c.at(temp.at(j));
      if (j + 1 > k) break;
      ll tempT = tempS;
      if (score > 0) {
        ll loop = (k - j - 1) / temp.size();
        tempT += score * loop;
      }
      ans = max(ans, tempT);
    }
  }

  cout << ans << endl;

  return 0;
}
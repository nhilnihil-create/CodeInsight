#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main () {
  int N;
  vector<int> P;
  vector<pair<int, int>> v;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    P.push_back(p);
    v.push_back(make_pair(p, i));
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  set<int> s;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long pos = v[i].second;
    int val = v[i].first;
    s.insert(v[i].second);

    set<int>::iterator itr1 = s.find(v[i].second);
    long long left = 0;
    bool add_left = false;
    if (itr1 != s.begin()) {
      itr1--;
      left = *itr1 + 1;
      add_left = true;
    }

    set<int>::iterator itr2 = s.find(v[i].second);
    bool add_right = false;
    itr2++;
    long long right = N - 1;
    if (itr2 != s.end()) {
      right = *itr2 - 1;
      itr2++;
      add_right = true;
    }

    if (add_left) {
      long long lleft = 0;
      if (itr1 != s.begin()) {
        itr1--;
        lleft = *itr1 + 1;
      } else {
        lleft = 0;
      }
      ans += val * (right - pos + 1) * (left - lleft);
    }

    if (add_right) {
      long long rright = 0;
      if (itr2 != s.end()) {
        rright = *itr2 - 1;
      } else {
        rright = N-1;
      }
      ans += val * (pos - left + 1) * (rright - right);
    }
  }
  cout << ans << endl;
}

// 1180_RecurringDecimals.cpp
//
#include <bits/stdc++.h>
using namespace std;

int a[30];
string _min, _max;
int buf, L;

void solve() {
  for(int i = 1; i < 21; ++i) {
    // L桁に整形
    ostringstream ss;
    ss << setw(L) << setfill('0') << a[i - 1];
    string s(ss.str());

    // 辞書順最大と最小を求める
    sort(s.begin(), s.end());
    _min = s;
    reverse(s.begin(), s.end());
    _max = s;

    // a_iを求める
    a[i] = stoi(_max) - stoi(_min);
    //cout << _max << " - " << _min << " = " << a[i] << endl;
    s = to_string(a[i]);

    // a_i = a_j を満たす最小のiを求める
    for(int j = 0; j < i; ++j) {
      if(a[j] == a[i]) {
        cout << j << ' ' << a[i] << ' ' << i - j << endl;
        return;
      }
    }
  }
}

int main() {
  while(cin >> a[0] >> L && a[0] && L) solve();
  return 0;
}


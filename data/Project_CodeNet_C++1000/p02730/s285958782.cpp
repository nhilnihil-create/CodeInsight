#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();

  auto is_kaibun = [](const string& str) {
    string comp = str;
    reverse(comp.begin(), comp.end());
    return str == comp;
  };

  if (!is_kaibun(s)) {
    cout << "No" << endl;
    return 0;
  }

  string sub1 = s.substr(0, (n - 1) / 2);
  if (!is_kaibun(sub1)) {
    cout << "No" << endl;
    return 0;
  }

  string sub2 = s.substr((n + 3) / 2 - 1);
  if (!is_kaibun(sub2)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}

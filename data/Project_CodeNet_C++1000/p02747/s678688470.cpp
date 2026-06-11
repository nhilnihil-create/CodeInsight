#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  bool ans = (s.size() % 2) == 0;
  for (int i = 0; i < s.size(); i++) ans &= s[i] == "hi"[i % 2];
  cout << (ans ? "Yes" : "No") << endl;
}

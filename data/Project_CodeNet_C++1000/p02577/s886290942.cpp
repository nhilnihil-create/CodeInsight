#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  unsigned long long sum;
  rep(i, 0, s.size()) { sum += s[i] - '0'; }
  cout << ((sum % 9) ? "No" : "Yes") << endl;
  getchar();
}
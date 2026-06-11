#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  string s;
  cin >> s;
  if (s.length() % 2 == 1) {
    cout << "No";
    return 0;
  }

  for (int i = 0; i < s.length(); i += 2) {
    string t = string();
    t += s[i];
    t += s[i + 1];
    if (t != "hi") {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
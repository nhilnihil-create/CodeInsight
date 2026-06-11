#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>

#define rep(i, n) for (auto i = 0; i < (n); i++)
#define MOD 1e9 + 7
typedef long long ll;

using namespace std;

int main() {
  int ans = 0;
  string s;
  cin >> s;
  if (s == "RRR") cout << 3 << endl;
  else if (s == "RRS" || s == "SRR") cout << 2 << endl;
  else if (s == "SSS") cout << 0 << endl;
  else cout << 1 << endl;

  return 0;
}


//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int m = 0;
  for (char c : s) {
    m += (int) (c - '0');
    m %= 9;
  }
  cout << (m == 0 ? "Yes" : "No") << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

char s;
void input() { cin >> s; }
void solve() { cout << ((isupper(s)) ? "A" : "a") << endl; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}

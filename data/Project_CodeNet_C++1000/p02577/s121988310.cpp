#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int ans = 0;
  ll size = S.size();
  for (ll i = 0; i < size; i++) {
    ans = (ans + (S[i] - '0')) % 9;
  }
  cout << (ans ? "No" : "Yes") << endl;
}
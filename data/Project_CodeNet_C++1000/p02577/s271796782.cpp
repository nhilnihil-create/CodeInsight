#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)

using namespace std;
using ll = long long;
const string YES = "Yes";
const string NO = "No";

void solve(string N) {
  ll sum(0);
  REP(i, N.length())
    sum += (N[i] - '0');
  cout << (sum % 9 ? NO : YES) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string N;
  cin >> N;

  solve(N);

  return 0;
}

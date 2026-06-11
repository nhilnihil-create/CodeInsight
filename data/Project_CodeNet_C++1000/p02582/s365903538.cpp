#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int ans = 0;
  string S;
  cin >> S;
  if (S == "RRR")
    cout << 3 << endl;
  else if (S == "SSS")
    cout << 0 << endl;
  else if (S == "RRS" || S == "SRR")
    cout << 2 << endl;
  else
    cout << 1 << endl;
}
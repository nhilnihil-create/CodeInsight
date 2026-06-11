#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  if (s.at(0) == 'S') cout << "Cloudy" << endl;
  else if (s.at(0) == 'C') cout << "Rainy" << endl;
  else cout << "Sunny" << endl;
}
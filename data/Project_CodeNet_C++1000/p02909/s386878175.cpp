#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  string s;
  cin >> s;
  if (s == "Sunny") cout << "Cloudy" << '\n';
  if (s == "Cloudy") cout << "Rainy" << '\n';
  if (s == "Rainy") cout << "Sunny" << '\n';
  return 0;
}
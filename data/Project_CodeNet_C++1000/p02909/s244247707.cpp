#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string weather[3] = {"Sunny", "Cloudy", "Rainy"}, s;
  cin >> s;

  if (s == weather[0])
    cout << weather[1] << "\n";
  else if (s == weather[1])
    cout << weather[2] << "\n";
  else
    cout << weather[0] << "\n";
}
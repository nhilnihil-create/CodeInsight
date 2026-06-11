#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  ll unit = 1, length = s.length(), r = 0, sum = 0;
  vector<ll> remainder(2019, 0);
  remainder[0]++;
  reverse(s.begin(), s.end());
  for (ll i = 0; i < length; i++){
    r = ((s[i] - '0') * unit + r) % 2019;
    sum += remainder[r];
    remainder[r]++;
    unit = unit * 10 % 2019;
  }
  cout << sum << '\n';
  return 0;
}

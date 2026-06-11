#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll num, sum = 0, a;
  cin >> num;
  for (ll i = 1; i <= num; i++){
    a = num / i;
    sum += ((1 + a) * a / 2) * i;
  }
  cout << sum << '\n';
  return 0;
}

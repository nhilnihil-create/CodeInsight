#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll num, sum = 0;
  map<ll, ll> divisor;
  cin >> num;
  ll limit = sqrt(num);
  for (int i = 2; i <= sqrt(num); i++)
    while(num % i == 0){
      num /= i;
      divisor[i]++;
    }
  if (num != 1)
    divisor[num]++;
  map<ll, ll>::iterator iter = divisor.begin();
  while (iter != divisor.end()){
    ll cnt = 1;
    while (iter->second - cnt >= 0){
      iter->second -= cnt;
      cnt++;
      sum++;
    }
    iter++;
  }
  cout << sum << '\n';
  return 0;
}

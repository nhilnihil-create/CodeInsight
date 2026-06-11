#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<ll, ll> Prime(ll n)
{
  map<ll, ll> ret;
  if (n == 1)
  {
    ret[1]++;
    return ret;
  }
  ll a = 2;
  while (n >= a * a)
  {
    if (n % a == 0)
    {
      ret[a]++;
      n /= a;
    }
    else
    {
      a++;
    }
  }
  ret[n]++;
  return ret;
}




int main()
{
  int n;cin>>n;
  cout << n << ":";
  auto m = Prime(n);
  for (auto && a : m) {
    while (a.second--) {
      cout << " " << a.first ;
    }
  }
  cout << endl;
}


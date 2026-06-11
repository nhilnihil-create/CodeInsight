#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll coun = 0;

int main()
{
  ll n;
  cin >> n;

  if (n % 2) {
    cout << 0 << endl;
    return 0;
  }

  ll x = 10;
  ll res = 0;
  while (n / x > 0) {
    res += n / x;
    x *= 5;
  }
  cout << res << endl;
}

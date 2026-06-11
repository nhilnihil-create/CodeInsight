#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  ll n, k;

  cin >> n >> k;

  ll mod = n % k;

  cout << min(abs(mod), abs(mod - k));


}

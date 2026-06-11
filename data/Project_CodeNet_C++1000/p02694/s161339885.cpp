#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

ll x;

int main()
{
  cin >> x;
  ll sum = 100;
  ll res = 0;
  while(sum < x)
  {
    sum += sum/100;
    res++;
  }
  cout << res << endl;
}
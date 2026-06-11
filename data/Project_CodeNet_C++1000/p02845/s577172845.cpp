#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const ll MOD = 1000000007;

int main()
{
  int N;
  cin >> N;
  vector<int> cnt(N + 1, 0);
  cnt.at(0) = 3;
  ll ans = 1;
  rep(i, N)
  {
    int a;
    cin >> a;
    a++;
    ans = (ans * (cnt.at(a - 1) - cnt.at(a))) % MOD;
    cnt.at(a)++;
  }
  cout << ans << endl;
}
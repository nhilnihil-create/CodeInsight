#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M, V, P;
vector<ll> A;
bool isGood(ll x) {
     if (x < P) return true;
     ll now = A[x] + M;
     if (A[P - 1] > now) return false;
     ll score = 0;
     score += (P - 1) * M;
     score += (N - x) * M;
     for (ll i = P - 1; i < x ; i++) {
         score += min(M, max(0ll, now - A[i]));
     }
     return score >= M * V;
 }


int main()
{
  cin >> N >> M >> V >> P;
  A = vector<ll>(N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  // cout << "A" << endl;
  // for (ll i = 0; i < N; ++i)
  // {
  //   cout << A.at(i) << ' ';
  // }
  // cout << endl;
  ll l = -1, r = N;
  ll m;
  while (l + 1 != r)
  {
    m = (l + r) / 2;
    if (isGood(m))
    {
      l = m;
    }
    else
    {
      r = m;
    }
  }
  cout << l + 1 << endl;
  // cout << "l" << l << endl;
}

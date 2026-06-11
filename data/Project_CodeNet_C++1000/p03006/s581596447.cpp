#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());
using ll = long long;
ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> pos(N);
  set<pair<int, int>> pos_set;
  rep(i, N)
  {
    cin >> pos[i].first >> pos[i].second;
    pos_set.insert(pos[i]);
  }

  if (N == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  SORT(pos);
  int ans = INT32_MAX;

  rep(i, N) rep(j, N)
  {
    ll p = pos[i].first - pos[j].first;
    ll q = pos[i].second - pos[j].second;
    if (p == 0 && q == 0)
      continue;

    int score = 0;
    set<pair<int, int>> temp_set = pos_set;

    for (pair<int, int> P : pos_set)
    {
      if (temp_set.find(P) == temp_set.end())
        continue;

      score++;
      pair<int, int> now = P;
      temp_set.erase(P);
      while (temp_set.size())
      {
        pair<int, int> next = now;
        next.first += p;
        next.second += q;
        if (temp_set.find(next) != temp_set.end())
        {
          temp_set.erase(next);
          now = next;
          continue;
        }

        break;
      }
    }
    ans = min(ans, score);
  }
  cout << ans << endl;
  return 0;
}
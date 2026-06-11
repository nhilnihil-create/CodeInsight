#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<ll> v;
  vector<ll> memory(n + 1, 0);
  v.push_back(1);
  memory[1] = 1;
  ll next;
  for (ll i = 0; i < n; i++)
  {
    if (memory[a[v[i] - 1]] == 1)
    {
      next = a[v[i] - 1];
      break;
    }
    v.push_back(a[v[i] - 1]);
    memory[a[v[i] - 1]] = 1;
  }
  ll ind = distance(v.begin(), find(v.begin(), v.end(), next));
  if (k < ind)
  {
    cout << v[k] << endl;
  }
  else
  {
    cout << v[(k - ind) % (v.size() - ind) + ind] << endl;
  }
}

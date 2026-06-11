#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> sp(n);
  rep(i, n) {
    int v;
    cin >> v;
    p[i] = sp[i] = v;
  }
  sort(sp.begin(), sp.end());
  int cnt = 0;
  rep(i, n)
  {
    if (p[i] != sp[i])
      cnt++;
    if (cnt >= 3)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
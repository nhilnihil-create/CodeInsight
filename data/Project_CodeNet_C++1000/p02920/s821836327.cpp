#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int count = 0;

int main()
{
  int n;
  cin >> n;
  multiset<int> s;
  int m = 1 << n;
  rep(i, m)
  {
    int t;
    cin >> t;
    s.insert(-t);
  }
  vector<int> created;
  created.push_back(*s.begin());
  s.erase(s.begin());
  rep(i, n)
  {
    int sz = created.size();
    rep(j, sz)
    {
      auto itr = s.upper_bound(created[j]);
      if (itr == s.end())
      {
        puts("No");
        return 0;
      }
      created.push_back(*itr);
      s.erase(itr);
    }
  }
  puts("Yes");
  return 0;
}
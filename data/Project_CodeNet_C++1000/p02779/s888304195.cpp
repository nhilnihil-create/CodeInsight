#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  set<int> st;
  bool ans = false;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    auto res = st.insert(a);
    ans = res.second;
    if (!ans)
    {
      break;
    }
  }
  if (ans)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

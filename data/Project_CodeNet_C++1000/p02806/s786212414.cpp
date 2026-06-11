#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, t, res;
  string s, X;
  cin >> N;
  vector<pair<string, int>> st(0);
  for (int i = 0; i < N; i++)
  {
    cin >> s >> t;
    st.push_back(make_pair(s, t));
  }
  cin >> X;
  for (int i = N - 1; i >= 0; i--)
  {
    if (st.at(i).first == X)
    {
      break;
    }
    else
    {
      res += st.at(i).second;
    }
  }
  cout << res << endl;
}

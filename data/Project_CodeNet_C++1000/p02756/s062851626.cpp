#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  int q;
  int rev = 0;
  cin >> s >> q;
  deque<char> dq(s.begin(), s.end());
  for (int i = 0; i < q; i++)
  {
    int query;
    cin >> query;
    if (query == 1)
    {
      rev++;
      continue;
    }

    if (query == 2)
    {
      int f;
      char c;
      cin >> f >> c;
      if (rev % 2 != 0)
      {
        if (f == 2)
        {
          dq.push_front(c);
        }
        else if (f == 1)
        {
          dq.push_back(c);
        }
      }
      else
      {
        if (f == 1)
        {
          dq.push_front(c);
        }
        else if (f == 2)
        {
          dq.push_back(c);
        }
      }
    }
  }
  if (rev % 2 != 0)
  {
    for (auto itr = dq.rbegin(); itr != dq.rend(); itr++)
    {
      cout << *itr;
    }
    cout << endl;
    return 0;
  }
  for (auto itr = dq.begin(); itr != dq.end(); itr++)
  {
    cout << *itr;
  }
  cout << endl;
}

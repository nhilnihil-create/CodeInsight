#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  deque<char> dq;
  for (int i = 0; i < (int)(S.size()); i++)
  {
    dq.push_back(S.at(i));
  }
  int64_t Q, t, f;
  char c;
  cin >> Q;
  bool reversed = false;
  for (int i = 0; i < Q; i++)
  {
    cin >> t;
    if (t == 1)
    {
      reversed = !reversed;
    }
    else
    {
      cin >> f >> c;
      if (f == 1 && !reversed || f == 2 && reversed)
      {
        dq.push_front(c);
      }
      else
      {
        dq.push_back(c);
      }
    }
  }
  if (reversed)
  {
    reverse(dq.begin(), dq.end());
  }
  while (dq.size())
  {
    cout << dq.front();
    dq.pop_front();
  }
  cout << endl;
}

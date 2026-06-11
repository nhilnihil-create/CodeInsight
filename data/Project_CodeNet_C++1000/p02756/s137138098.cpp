#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int64_t Q, t;
  cin >> Q;
  bool reversed = 0;
  deque<char> dq;
  for (int i = 0; i < S.size(); i++)
  {
    dq.push_back(S[i]);
  }
  int f;
  char c;
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
      if ((f == 1 && !reversed) || (f == 2 && reversed))
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
    while (dq.size())
    {
      cout << dq.back();
      dq.pop_back();
    }
  }
  else
  {
    while (dq.size())
    {
      cout << dq.front();
      dq.pop_front();
    }
  }
  cout << endl;
}
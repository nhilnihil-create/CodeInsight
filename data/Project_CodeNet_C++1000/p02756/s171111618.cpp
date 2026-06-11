#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<char> s;
  string tmp;
  cin >> tmp;
  for (auto &&i : tmp)
  {
    s.push_back(i);
  }
  int q;
  cin >> q;
  int rev_flag = 1;
  for (size_t i = 0; i < q; i++)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      rev_flag *= -1;
    }
    else if (t == 2)
    {
      int f;
      cin >> f;
      if (f == 2)f = -1;
      char c;
      cin >> c;
      if (f*rev_flag == 1)
      {
        s.push_front(c);
      }
      else if (f*rev_flag == -1)
      {
        s.push_back(c);
      }
      else
      {
        cout << "err" << endl;
      }
    }
    else
    {
      cout << "err" << endl;
    }
  }
  if (rev_flag == -1)
  {
    reverse(s.begin(), s.end());
  }
  
  for (auto &&a : s)
  {
    cout << a;
  }
  cout << "\n";

}
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int tt;
  tt = 1;
  while (tt--)
  {
    string s;
    cin >> s;
    int i, count = 0;
    vector<int> v;
    for (i = 0; i < s.length(); i++)
    {
      if (s[i] == 'R')
      {
        count = 0;
        while (s[i] == 'R')
        {
          count++;
          i++;
        }
        i--;
        v.push_back(count);
      }
    }
    sort(v.begin(), v.end());
    if (v.size() == 0)
    {
      cout << "0" << endl;
    }
    else
    {
      cout << v[v.size() - 1] << " " << endl;
    }
  }
  return 0;
}
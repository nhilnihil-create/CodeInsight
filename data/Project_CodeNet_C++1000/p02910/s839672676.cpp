#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  vector<char> odd = {'R', 'U', 'D'};
  vector<char> even = {'L', 'U', 'D'};

  int ans = 1;
  for (int i = 0; i < s.length(); i++)
  {
    if (i % 2 == 0)
    {
      if (find(odd.begin(), odd.end(), s[i]) == odd.end())
      {
        ans = 0;
      }
    }
    else
    {
      if (find(even.begin(), even.end(), s[i]) == even.end())
      {
        ans = 0;
      }
    }
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}

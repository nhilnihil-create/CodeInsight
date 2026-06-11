#include <bits/stdc++.h>
using namespace std;

int main()
{
 int n, s; cin >> n >> s;
 vector<int> v(n+1, 0); int penalties = 0; int  corrects = 0;
 vector<int> wrongs(n+1, 0);
  while(s--)
  {
    int id; string res; cin >> id >> res;
    if(res == "WA")
    {
      if(v[id] == 0) wrongs[id]++;
    }
    else
    {
      
      if(v[id] == 0)
          ++corrects;
        v[id] = 1;
    }
  }
  for(int i = 1; i <= n; ++i)
    if(v[i]) penalties += wrongs[i];
  cout << corrects << " " << penalties;
  
  return 0;
}

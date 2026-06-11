#include <bits/stdc++.h>

using namespace std;

int N;
string s;

void solve()
{
  cin >> N >> s;
  int count=0;
  s.push_back('#');
  for(int i=0; i+1 < s.size(); i++)
  {
    if(s[i] != s[i+1])
      count++;
  }
  cout << count << endl;
}
  
int main()
{
  solve();
  return 0;
}
  
        
        
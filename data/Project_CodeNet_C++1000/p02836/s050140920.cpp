#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>> s;
  string s1,s2;
  s1 = s.substr(0, s.length()/2);
  s2 = s.substr(s.length()/2 + s.length()%2, s.length());
  reverse(s2.begin(), s2.end());
  long long ans = 0;
  for (size_t i = 0; i < s.length()/2; i++)
  {
    if (s1[i] != s2[i])
    {
      ans++;
    }
    
  }
  
  cout << ans << endl;
}

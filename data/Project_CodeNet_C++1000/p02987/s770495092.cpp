#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  string s;
  cin >> s ;

  bool ans = false;

  sort(s.begin(),s.end());
  if(s.at(0) == s.at(1) && s.at(2) == s.at(3) && s.at(0) != s.at(2)) ans = true;
  if(ans) puts("Yes");
  else puts("No");
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s;
  cin >> s;
  rep(i, s.size())
    if ((i % 2 == 1 && s[i] == 'R') || (i % 2 == 0 && s[i] == 'L'))
    {
      puts("No");
      return 0;
    }
  puts("Yes");
  return 0;
}
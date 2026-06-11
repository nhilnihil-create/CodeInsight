#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s;
  cin >> s;
  if (s == "SUN")
    puts("7");
  else if (s == "MON")
    puts("6");
  else if (s == "TUE")
    puts("5");
  else if (s == "WED")
    puts("4");
  else if (s == "THU")
    puts("3");
  else if (s == "FRI")
    puts("2");
  else if (s == "SAT")
    puts("1");
  return 0;
}
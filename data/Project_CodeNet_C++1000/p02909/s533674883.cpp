#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int count = 0;

int main()
{
  string s;
  cin >> s;
  if (s == "Sunny")
    puts("Cloudy");
  else if (s == "Cloudy")
    puts("Rainy");
  else
    puts("Sunny");
  return 0;
}
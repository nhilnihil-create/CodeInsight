#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b + c >= 22)
    puts("bust");
  else
    puts("win");
  return 0;
}
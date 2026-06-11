#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int a, b;
  cin >> a >> b;
  if (a >= 1 && a <= 9 && b >= 1 && b <= 9)
    cout << a * b << endl;
  else
    puts("-1");
  return 0;
}
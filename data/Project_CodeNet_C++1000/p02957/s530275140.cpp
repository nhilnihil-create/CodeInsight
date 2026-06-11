#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int a, b;
  cin >> a >> b;
  if (abs(a - b) % 2 == 0)
    cout << (a + b) / 2 << endl;
  else
    cout << "IMPOSSIBLE\n";
  return 0;
}
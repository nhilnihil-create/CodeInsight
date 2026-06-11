#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a, b;
  cin >> a >> b;
  if (a != 3 && b != 3) cout << 3 << endl;
  else if(a != 2 && b != 2) cout << 2 << endl;
  else cout << 1 << endl;
  return 0;
}

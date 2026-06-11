#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a,b,x;
  cin >> a >> b;
  x = a + b;
  cout << (x * (x - 1) / 2) - (a * b) << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int a, b;
  cin >> a >> b;
  printf("%d\n", max(0, a - b * 2));
  return 0;
}
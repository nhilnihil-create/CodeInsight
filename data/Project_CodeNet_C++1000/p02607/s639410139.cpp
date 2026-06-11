#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, a;
  cin>>n;
  int res = 0;
  for (int i=1; i<=n; i++)
  {
    cin>>a;
    if (i%2 && a%2) res++;
  }
  
  cout << res << '\n';
  return 0;
}
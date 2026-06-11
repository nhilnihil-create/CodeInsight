#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  cin >> n;
  long long ans = 0;
  //for(int i=1; i<=20; i++) cout << uoc_so(i) << '\n';
  for(int a=1; a < n; a++)
  {
    int b = (n-1)/a;
    ans += b;
  }
  cout << ans;
  return 0;
}

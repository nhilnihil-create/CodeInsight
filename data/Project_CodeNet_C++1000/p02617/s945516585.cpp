#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

int main()
{
  int n;
  cin >> n;

  LL res = 0;
  for(int i = 1; i <= n; ++i)
  {
    res += 1LL * i * (n-i+1);
  }
  for(int i = 0; i < n-1; ++i)
  {
    int u, v;
    cin >> u >> v;
    if(u > v) swap(u, v);
    res -= 1LL * u * (n-v+1);
  }
  cout << res << endl;
  
  return 0;
}

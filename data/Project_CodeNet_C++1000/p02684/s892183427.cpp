#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,k;cin>>n>>k;
  static 
  int dl[65][200000];
  for (size_t i = 1; i <= n; i++)
  {
    cin >> dl[0][i];
  }
  
  for (size_t i = 1; i < 64; i++)
  {
    for (size_t j = 1; j <= n; j++)
    {
      dl[i][j] = dl[i-1][dl[i-1][j]];
    }
    
  }
  
  int ans = 1;
  for (size_t i = 0; i < 64; i++)
  {
    if (k & (1LL<<i))
    {
      ans = dl[i][ans];
    }

  }
  
  cout << ans << endl;
  
}
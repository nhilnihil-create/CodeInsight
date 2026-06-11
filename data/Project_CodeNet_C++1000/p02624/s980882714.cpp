#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define float long double 

int32_t main()
{
  IOS;
  int n;
  cin>>n;
  vector<int> v(n+1,0);
  for(int i=1; i<=n; i++)
  {
    for(int j=i; j<=n; j+=i)
    {
      v[j]++;
    }
  }
  
  int total = 0;
  for(int i=1; i<=n; i++)
  {
    total += i*v[i];
  }

  cout<<total<<endl;
  
  return 0;
}
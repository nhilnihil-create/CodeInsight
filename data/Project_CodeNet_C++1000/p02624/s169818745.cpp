#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,i,j,tot=0;
  cin>>n;
  for (i = 1; i <= n; ++i)
  {
        for(j=i;j<=n;j+=i)
        {
            tot+=j;
        }
  }
  cout<<tot;
  return 0;
}

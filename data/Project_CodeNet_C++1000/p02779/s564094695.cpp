#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
ll a[40001000];
//ll number[20],used[20];
int main()
{
  ll i,j,count =0,n;
  cin>> n;
  for(i=0;i<n;i++)
    cin>> a[i];
  sort(a,a+n);
  for(i=0;i<n-1;i++)
  {
      if(a[i]!=a[i+1])
        count=0;
      else
      {
          count=1;
          break;
      }
  }
  if(count==0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
    return 0;
}

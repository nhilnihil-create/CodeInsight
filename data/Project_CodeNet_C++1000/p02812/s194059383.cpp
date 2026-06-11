#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  int n;
  cin>>n;
  string a;
  cin>>a;
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]=='A')
    {
      if(i+1<n && a[i+1]=='B')
      {
        if(i+2<n && a[i+2]=='C')
        {
          count++;
        }
      }
    }
  }

  cout<<count<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int c,d;
  int count=0;
  for(int i=0;i<n;i++)
  {
    cin>>c>>d;
    if(c==d)
    {
      count++;
      if(count==3)
      {
        cout<<"Yes";
        return 0;
      }
    }
    else
      count=0;
  }
  cout<<"No";
  return 0;
}
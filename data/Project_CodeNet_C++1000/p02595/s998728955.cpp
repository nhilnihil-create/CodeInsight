#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long int d;
  cin>>d;
  int c=0;
  long long int x,y;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    if(x*x+y*y<=d*d)
     c++;
  }
  cout<<c<<endl;
  return 0;
}
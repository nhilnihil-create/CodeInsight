#include<iostream>
using namespace std;
int main()
{
  int n,c=1,d;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  d=a[0];
  for(int i=1;i<n;i++)
  {
    if(a[i]<=d)
    {
      c++;
      d=a[i];
    }
  }
  cout<<c<<endl;
}

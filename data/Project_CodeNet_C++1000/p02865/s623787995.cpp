#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if(n%2!=0)
  {
    int k=n/2;
    cout<<k<<endl;
  }
  else
  {
    int k=n/2;
    cout<<k-1<<endl;
  }
  return 0;
}
#include<iostream>
using namespace std;
int main (void)
{
  long long int n,k;
  cin>>k;
  n=0;
  for(int i=1;i<1000000;i++)
  {
    n=10*n+7;
    n=n%k;
    if(n==0){cout<<i<<endl;return 0;}

  }
  cout<<"-1"<<endl;
}
#include<iostream> 
using namespace std;
 
int main()
{
  int n;
  cin>>n;
  long long ans=n-1;
  ans=ans*(ans+1)/2;
  cout<<ans;
}
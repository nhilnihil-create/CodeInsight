#include<iostream>
using namespace std;
int main (void)
{
  long long int h,a;
  int n,i;
  cin>>h>>n;
  for(i=0;i<n;i++)
  {
    cin>>a;
 
    h=h-a;
   
    if(h<=0)
    {
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  
  cout<<"No"<<endl;
  return 0;
}
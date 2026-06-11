#include<iostream>
using namespace std;
int main()
{
  int n,i,c=0;
  cin>>n;
  int ar[n];
  for(i=0; i<n; i++)
  {
    cin>>ar[i];
  }
  for(i=0; i<n; i++)
  {
    if((i+1)%2!=0 && (ar[i]%2)!=0)
      c++;
  }
  cout<<c;
  
}

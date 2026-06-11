#include<iostream>
using namespace std;
int main()
{
  int n,j,i,temp=1,count=0,flag=0;
  cin>>n;
  for( j=0;j<n;j++)
  {
  	cin>>i;
    if(i!=temp)
      count++; 
    if(i==temp)
      temp++;
  }
  if(temp==1)
      cout<<"-1";
  else
  	cout<<count;
  return 0;
}  
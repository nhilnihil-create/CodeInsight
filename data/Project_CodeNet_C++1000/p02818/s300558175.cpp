#include<iostream>
using namespace std;
int main (void)
{
  long long int i,j,k,l,a,b,n,ans;
  cin>>a>>b>>k;
  if(k<a){cout<<a-k<<" "<<b<<endl;}
  else if(k<a+b){cout<<"0 "<<a+b-k<<endl;}
  else {cout<<"0 0"<<endl;}

}
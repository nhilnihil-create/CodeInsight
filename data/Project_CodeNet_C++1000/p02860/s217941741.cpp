#include<iostream>
using namespace std;
int main (void)
{
  int n,i,j,k;
  string s;
  cin>>n>>s;
  if(n%2==0)
  {
     for(i=0;i<n/2;i++)
     {
       if(s[i]!=s[i+n/2])
       {
         cout<<"No";return 0;
       }
     }
     cout<<"Yes";
  }
  else{cout<<"No";}
}
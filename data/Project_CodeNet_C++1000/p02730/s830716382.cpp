#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
   
  string s;
  cin>>s;
  int n,i;
  n=s.size();
    for(i=0;i<n/2;i++)
  {
    if(s[i]!=s[n-1-i]){cout<<"No"<<endl;return 0;}
  }
  n=n/2;
  for(i=0;i<n/2;i++)
  {
    if(s[i]!=s[n-1-i]){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}
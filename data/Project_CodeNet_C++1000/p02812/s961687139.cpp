
#include<iostream>
using namespace std;
int main (void)
{
  int n;
  string s;
  cin>>n>>s;
  int i,j;
  j=0;
  for(i=0;i<n-2;i++)
  {
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){j++;}
  }
  cout<<j<<endl;

}
#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  string s;
  cin>>s;
  int n,i,j,k;
  n=s.size();
  for(i=0;i<n;i++)
  {
  if(i%2==0&&(s[i]=='R'||s[i]=='U'||s[i]=='D')){}
  else if(i%2==1&&(s[i]=='L'||s[i]=='U'||s[i]=='D')){}
  else {cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
}
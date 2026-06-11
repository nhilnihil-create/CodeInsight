#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
 string s;
  int i;
  cin>>s;
  for(i=0;i<3;i++)
  {if(s[i]==s[i+1]){cout<<"Bad"<<endl;return 0;}}
  cout<<"Good"<<endl;
  
}
 
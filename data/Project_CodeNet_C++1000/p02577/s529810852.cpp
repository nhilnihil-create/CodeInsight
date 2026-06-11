#include<bits/stdc++.h>
using namespace std;

void solve()
{
  string s;
  cin>>s;
  int i=0;
  int sum=0;
 while(s[i]!='\0')
  {
    sum+=s[i]-'0';
   
   i++;
  }
  if(sum%9==0)
    cout<<"Yes";
  else
    cout<<"No";
  return;
  
  
}
int main()

{
   solve();
}

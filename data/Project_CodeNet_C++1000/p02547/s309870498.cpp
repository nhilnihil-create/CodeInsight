#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,a,b;
  cin>>n;
  int c=0;
  string ans="No";
  while(n--)
  {
    cin>>a>>b;
    if(a==b)
      c++;
    else
      c=0;
    if(c>=3){
    	ans="Yes";}
  }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int m,n,l,i,r=0;
  cin>>s;
  l=s.size();
  if(l%2==0)
  {

    m=(l/2)-1;
    n=l-1;
    for(i=0;i<=m;i++)
    {
      if(s[i]!=s[n]) r++;
      n--;
    }
   }
else
{
  m=(l/2)-1;
  n=l-1;
  for(i=0;i<=m;i++)
  {
    if(s[i]!=s[n]) r++;
    n--;
  }
}
cout<<r<<endl;

}

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,c;
  string str;
  cin>>n;
  cin>>str;
  c=1;
  for(i=0;i<n-1;i++)
  {
      if(str[i]!=str[i+1])
      {
          c++;
      }
  }
  cout<<c<<endl;
}

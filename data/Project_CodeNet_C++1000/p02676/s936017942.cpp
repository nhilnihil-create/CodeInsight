#include<bits/stdc++.h>
using namespace std;

int main()
{

int k;
  cin>>k;
 string s;
  cin>>s;
  if(s.length()<=k)
  {
  cout<<s;
    return 0;
  }
  else
  {
     string neww=s.substr(0,k);
    neww+="...";
    cout<<neww;
  }
  
   
}
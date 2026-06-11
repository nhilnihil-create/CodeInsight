#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n=s.length();
  if(s[n-1]=='s')
  {
    s.append(1,'e');
    s.append(1,'s');
    cout<<s;
  }
  else
  {
     s.append(1,'s');
    cout<<s;
  }
}

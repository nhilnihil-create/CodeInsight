#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
  if(s.back()=='s')
  {
    return s+"es";
  }
  else
  {
    return s+'s';
  }
}

int main()
{
  string s;
  cin>>s;
  
	cout<<solve(s)<<"\n";
  return 0;
}

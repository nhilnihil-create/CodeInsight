#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n = s.length();
  if(s[n-1] != 's'){
  	s += 's';
  }
  else if(s[n-1] == 's'){
  	s += "es";
  }
  cout<<s<<endl;

}
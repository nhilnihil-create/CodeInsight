#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
int sw,i;
  
cin >> s;
  for(i=0;i<s.size();++i)
  {
  if(i%2==0) 
  {if(s.at(i)=='R' || s.at(i)=='U' || s.at(i)=='D') sw++;}
  else 
  {if(s.at(i)=='L' || s.at(i)=='U' || s.at(i)=='D') sw++;}
  }
  if(sw==s.size()) cout << "Yes";
  else cout << "No";
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int k;
  cin>>k;
  string s;
  cin>>s;
  int n=s.length();
  if(n>k)
  {
    int i=0;
    while(i<k)
    {
      cout<<s[i];
      i++;
    }
    cout<<"...";
  }
  else
    cout<<s<<"\n";
}

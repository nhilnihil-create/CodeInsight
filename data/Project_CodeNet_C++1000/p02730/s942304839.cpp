#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pallindrome(string s)
{
    string t(s.rbegin(),s.rend());
    return s==t;
}
int main()
{
   string s;
   cin>>s;
   int n=s.size();
   bool f=true,b=true;
   if(pallindrome(s)&&pallindrome(s.substr(0,(n-1)/2))&&pallindrome(s.substr((n+1)/2)))
   cout<<"Yes\n";
   else
   cout<<"No\n";
}

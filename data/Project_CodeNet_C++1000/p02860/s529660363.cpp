#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() 
{
   cin>>n>>s;
   if(n%2==1)
   {
      cout<<"No";
      return 0;
  }
   string a=s.substr(0,n/2),b=s.substr(n/2,n/2);
   if(a==b) 
   {
      cout<<"Yes";
      return 0;
   }
    cout<<"No";
}
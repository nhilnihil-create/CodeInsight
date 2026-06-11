#include<iostream>
using namespace std;
int main (void)
{
 string s,t,l;
  cin>>s>>t;
  l=t;
  l=l.erase(s.size());

 if(s==l){cout<<"Yes";}
  else{cout<<"No";}
}
 
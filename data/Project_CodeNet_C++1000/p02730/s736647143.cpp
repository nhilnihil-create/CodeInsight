#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main() {
  string s;
  cin>>s;
  string h=s;
  reverse(h.begin(),h.end());
  int N=s.size();
  string t=s.substr(0,(N-1)/2);
  string p=s.substr(0,(N-1)/2);
  reverse(p.begin(),p.end());
  string d=s.substr((N+3)/2-1);
  string y=s.substr((N+3)/2-1);
  reverse(y.begin(),y.end());
  //cout<<t<<endl<<p<<endl<<d<<endl<<y<<endl;
  if(s==h&&t==p&&d==y){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}
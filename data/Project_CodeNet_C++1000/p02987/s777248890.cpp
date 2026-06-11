#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c,d; cin>>a>>b>>c>>d;
  if(a==b && a!=c && a!=d &&b!=c && b!=d){
    if(c==d)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  else if(a==c && a!=b && a!=d && c!=b && c!=d){
    if(b==d)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  else if(a==d && a!=b && a!=c && d!=b && c!=d){
    if(b==c)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  else
    cout<<"No"<<endl;
}
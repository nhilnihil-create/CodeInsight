#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin>>a>>b>>c;
  if(a==b&&a!=c)
    cout<<"Yes"<<endl;
  else if(b==c&&a!=b)
    cout<<"Yes"<<endl;
  else if(a==c&&b!=a)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
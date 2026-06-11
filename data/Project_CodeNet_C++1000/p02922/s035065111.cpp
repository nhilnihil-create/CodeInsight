#include <bits/stdc++.h>
using namespace std;

int main(){
  double a,b,c;
  int d;
  cin>>a>>b;
  c=(b-1)/(a-1);
  d=c;
  if(c!=d){
    cout<<d+1<<endl;
  }
  else{
    cout<<c<<endl;
  }
}

#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {

  int x,y,z;cin>>x>>y>>z;
  
  int sum=x+y+z;
  
  if(sum<22){
    cout<<"win"<<endl;
  }
  else{
    cout<<"bust"<<endl;
  }
}
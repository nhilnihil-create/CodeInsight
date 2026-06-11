#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,flag;
  cin>>a>>b>>c;
  flag=0;
  if((a==b) && (a!=c)){
    flag=1;
  }
  if((a==c) && (b!=c)){
    flag=1;
  }
  if((b==c) && (a!=c)){
    flag=1;
  }
  if(flag==1){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}
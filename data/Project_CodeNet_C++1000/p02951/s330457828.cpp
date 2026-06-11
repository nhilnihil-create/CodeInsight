#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0,b=0,c=0;
  cin>>a>>b>>c;
  int d=a-b;
  if(d<c){
    cout<<c-d<<endl;
  }
  else if(d>=c){
    cout<<'0'<<endl;
  }
}

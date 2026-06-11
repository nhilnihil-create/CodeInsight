#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=a-b;
  if(d>=c){
    cout<<0<<endl;
  }
  else{
    cout<<(c-d)<<endl;
  }
}
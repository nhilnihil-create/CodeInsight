#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(abs(a-b)>=c){
    cout<<0<<endl;
  }
  else{
  cout<<c-abs(a-b);
  }
  return 0;
}
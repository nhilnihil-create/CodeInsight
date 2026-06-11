#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  if(b==1){cout<<0<<endl;}
  else{
    cout<<((b-1)+(a-2))/(a-1)<<endl;
  }
}
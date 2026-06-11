#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b,c;
  cin>>a>>b;
  c=a+b;
  if(c%2==0)cout<<c/2<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  
  return 0;
}
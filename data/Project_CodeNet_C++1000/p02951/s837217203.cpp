#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(c-a+b>=0)cout<<c-a+b<<endl;
  else cout<<0<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,l,c=0;
  cin>>n>>d>>l;
  for(int i=n;i<=d;i++){
    if(i%l==0)
      c++;
  }cout<<c;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,sum=0;
  cin>>a>>b;
  if(b==1){
    cout<<0<<'\n';
    return 0;
  }
  cout<<a-b<<'\n';
  return 0;
}

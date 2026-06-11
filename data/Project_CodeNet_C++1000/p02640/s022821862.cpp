#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  bool s=false;
  for(int i=0;i<=n;i++){
    if(2*i+4*(n-i)==m) s=true;
  }
  if(s) cout <<"Yes"<<endl;
  else cout <<"No" <<endl;
}
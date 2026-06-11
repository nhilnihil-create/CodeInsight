#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,m; cin>>n>>m;
  while(m--){
    int a; cin>>a;
    n-=a;
  }
  if(n<0) cout<<-1;
  else cout<<n;
  return 0;
}
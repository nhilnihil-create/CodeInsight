#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,i=1,x; cin>>n>>k;
  x=k;
  while(x<=n){
    i++; x*=k;
  }
  cout<<i<<endl;
}
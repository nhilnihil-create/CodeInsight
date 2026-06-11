#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,h,a;
  cin>>h>>a;
  for(i=0;i<h;i++){
    i=i+a-1;
  }
    cout<<i/a<<'\n';
  return(0);
}

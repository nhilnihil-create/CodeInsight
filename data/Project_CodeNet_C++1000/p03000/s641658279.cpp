#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,x;
  cin>>n>>x;
  vector<int>l(n);
  int a=0;
  int b=0;
  for(int i=0;i<n;i++){
  cin>>l.at(i);
  a+=l.at(i);
  b++;
  if(a>x){
  cout<<b;
  return 0;
  }
  }
  if(a<=x){
    cout<<b+1;
  }
  else{
  cout<<b;
  }
 }
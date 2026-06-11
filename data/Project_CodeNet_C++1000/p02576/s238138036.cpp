#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x,t;
  cin>>n>>x>>t;
  int a;
  if(n%x==0){
    a=n/x;
  }
  else{
    a=n/x +1;
  }
  cout<<a*t<<endl;
}

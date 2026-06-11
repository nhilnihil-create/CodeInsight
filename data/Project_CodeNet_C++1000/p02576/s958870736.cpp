#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n,x,t;
  cin>>n>>x>>t;
  
  int c = n/x;
  if(n%x!=0){
      c++;
  }
  cout<<t*c<<endl;
}

#include <bits/stdc++.h>
using namespace std;



int main(){
  long long W,H,x,y;
  cin>>W>>H>>x>>y;
  
  cout<<fixed<<setprecision(12)<<W*H/2.0<<" ";
  
  if(2*x==W&&2*y==H){
    cout<<1<<endl;
  }
  else cout<<0<<endl;
}
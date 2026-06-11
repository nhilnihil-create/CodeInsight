#include <bits/stdc++.h>
using namespace std;

int main(){
  long double W,H,x,y;
  cin>>W>>H>>x>>y;
  cout<<fixed<<setprecision(1)<<W*H/2.0<<' ';
  if(W==x*2 && H==y*2)
    cout<<1<<endl;
  else
    cout<<0<<endl;
}
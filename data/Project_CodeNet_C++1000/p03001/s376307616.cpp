#include <bits/stdc++.h>
using namespace std;
int main(){
  long double H,W,h,w; cin>>H>>W>>h>>w;
  cout<<fixed<<setprecision(10)<<H*W/2.0<<" "<<fixed<<setprecision(0)<<(H/2==h&&W/2==w? 1:0)<<endl;
}
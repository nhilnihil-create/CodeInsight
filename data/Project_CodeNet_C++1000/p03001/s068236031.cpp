#include<bits/stdc++.h>
using namespace std;
int main() {
  int64_t w,h,x,y;
  cin>>w>>h>>x>>y;
  cout<<0.5*w*h<<' ';
  if(w%2==0 && h%2==0 && x==w/2 && y==h/2) cout<<1<<endl;
  else cout<<0<<endl;
}
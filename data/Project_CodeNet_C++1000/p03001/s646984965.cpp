#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  ll w,h,x,y;
  cin>>w>>h>>x>>y;
  int num=(x+x==w)&&(y+y==h);
  cout<<(double)w*h/2<<" "<<num<<endl;
  return 0;
}
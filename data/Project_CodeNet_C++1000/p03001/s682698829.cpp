#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cout<<setprecision(10)<<fixed;
  long double w,h,x,y;
  cin>>w>>h>>x>>y;
  long double cenx=w,ceny=h;
  cenx/=2;
  ceny/=2;
  int hantei=0;
  if(x==cenx&&y==ceny){
    hantei=1;
  }
  long double ans=w*h;
  ans/=2;
  cout<<ans<<" "<<hantei<<endl;
}
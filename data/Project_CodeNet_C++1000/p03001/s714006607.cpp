#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  double w,h,x,y;
  cin >> w>>h>>x>>y;
  double ans;
  ans=w*h/2;
  if(x*2==w && y*2==h ){
    printf("%lf 1",ans);
  }else{
    printf("%lf 0",ans);
  }
}

    

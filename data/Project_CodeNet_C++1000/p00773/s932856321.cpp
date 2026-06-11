#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
int func(int a,int b){
  return (int)(a*(100.0+b)/100.0);
}
int main(void){
  int a,b,c;
  while(cin>>a>>b>>c,a||b||c){
    int ans=0;
    loop(i,1,1000){
      loop(j,1,1000){
	if(func(i,a)+func(j,a)==c)ans=max(ans,func(i,b)+func(j,b));
      }
    }
    cout<<ans<<endl;
  }
}


  /*int bf,af,bsum;
  while(cin>>bf>>af>>bsum,bf+af+bsum){
    int res = -1;
    double aper = (100.0+af)/100;
    double bper = 100.0/(100+bf);
    loop(i,1,bsum/2 + 3){
      int x = (i + 0.999) * bper , y = (bsum - i + 0.999) * bper;
      //cout<<" "<<yt-(int)yt<<" "<<xt-(int)xt<<endl;
      //cout<<i<<" "<<bsum-i<<" "<<x<<" "<<y<<" "<<res<<endl;
      res = max(res,(int)(x*aper)+(int)(y*aper));
      cout<<res<<" "<<x<<" "<<y<<endl;
    }
    
    cout<<res<<endl;
  }
  
}
  */
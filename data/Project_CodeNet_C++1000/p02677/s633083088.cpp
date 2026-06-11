#include<bits/stdc++.h>
using namespace std;
using ll=long long;
double pi=3.141592653589;

int main(){
  int a,b,h,m;
  cin>>a>>b>>h>>m;
  int akaku=h*60+m;
  int bkaku=12*m;
  int dkaku=abs(akaku-bkaku);
  double ans;
  double drad=(double)dkaku*pi/360;
  ans=sqrt((double)a*(double)a+(double)b*(double)b-2*(double)a*(double)b*cos(drad));
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
 
}
    
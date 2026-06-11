#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;
const double PI=acos(-1);
int main(){
  int a, b, h, m;
   cin >> a >> b >> h >> m;
  double M=m/2.0;
  double Min=min(abs(30*h+M-6*m),360-abs(30*h+M-6*m));
  double x=Min/180.0;
  
  double ans=sqrt(a*a+b*b-2*a*b*cos(x*PI));
  
  printf("%.12f\n",ans);
  
}

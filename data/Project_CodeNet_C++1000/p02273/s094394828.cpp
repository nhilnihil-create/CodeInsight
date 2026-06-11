#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
const double EPS = 1e-10;//sample:if((double)>=(double)+EPS)
#define CLR(a) memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)  cerr << #x << " = " << (x) << endl;//debug
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);
int cnt=0,n;

using namespace std;
void koch(int n,double p1x, double p1y, double p2x, double p2y){
  double sx,sy,tx,ty,ux,uy,th=M_PI*60.00/180.0;
  if(n==0)return;
  sx=(2.0*p1x+p2x)/3;
  sy=(2.0*p1y+p2y)/3;
  tx=(p1x+2.0*p2x)/3;
  ty=(p1y+2.0*p2y)/3;
  ux=(tx-sx)*cos(th)-(ty-sy)*sin(th)+sx;
  uy=(tx-sx)*sin(th)+(ty-sy)*cos(th)+sy;
  koch(n-1,p1x,p1y,sx,sy);printf("%.8f %.8f\n",sx,sy);
  koch(n-1,sx,sy,ux,uy);printf("%.8f %.8f\n",ux,uy);
  koch(n-1,ux,uy,tx,ty);printf("%.8f %.8f\n",tx,ty);
  koch(n-1,tx,ty,p2x,p2y);
  cnt++;
  
  
  
  
}
int main(){
  cin>>n;
  printf("%.8f %.8f\n",0.0,0.0);
  koch(n,0,0,100,0);
  printf("%.8f %.8f\n",100.0,0.0);
  return 0;
}


#include <cstdio>
#include <utility>
#include <cmath>

using namespace std;

void rec(pair<double,double> x,pair<double,double> y,int n){
  if(n<=0) return;
  pair<double,double> t=make_pair((2*y.first+x.first)/3,(2*y.second+x.second)/3);
  pair<double,double> s=make_pair((y.first+2*x.first)/3,(y.second+2*x.second)/3);
  double u_1=(s.first+t.first)/2+sqrt(3)*(s.second-t.second)/2;
  double u_2=(s.second+t.second)/2+sqrt(3)*(t.first-s.first)/2;
  pair<double,double> u=make_pair(u_1,u_2);
  rec(x,s,n-1);
  printf("%lf %lf\n",s.first,s.second);
  rec(s,u,n-1);
  printf("%lf %lf\n",u.first,u.second);
  rec(u,t,n-1);
  printf("%lf %lf\n",t.first,t.second);
  rec(t,y,n-1);
}

int main(){
  int n; scanf("%d",&n);
  const pair<double,double> p_1=make_pair(0,0);
  const pair<double,double> p_2=make_pair(100,0);
  printf("%lf %lf\n",p_1.first,p_1.second);
  rec(p_1,p_2,n);
  printf("%lf %lf\n",p_2.first,p_2.second);
}
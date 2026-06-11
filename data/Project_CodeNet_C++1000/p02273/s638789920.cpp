#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

vector<pair<double,double> > point;
vector<pair<double,double> >::iterator it;

void koch(int n,pair<double,double> start,pair<double,double> end){
  if(n==0) return;
  pair<double,double> s,t,u;
  double x_sum=(end.first-start.first)/3;
  double y_sum=(end.second-start.second)/3;
  double distance=sqrt(pow(x_sum,2)+pow(y_sum,2));
  s.first=start.first+x_sum;
  s.second=start.second+y_sum;
  u.first=start.first+x_sum*2;
  u.second=start.second+y_sum*2;
  t.first=(u.first-s.first)*cos(M_PI/3)-(u.second-s.second)*sin((M_PI/3))+s.first;
  t.second=(u.first-s.first)*sin(M_PI/3)+(u.second-s.second)*cos(M_PI/3)+s.second;
  koch(n-1,start,s);
  printf("%.8f %.8f\n",s.first,s.second);
  koch(n-1,s,t);
  printf("%.8f %.8f\n",t.first,t.second);
  koch(n-1,t,u);
  printf("%.8f %.8f\n",u.first,u.second);
  koch(n-1,u,end);
}

int main(){
  int com_n=0;
  cin >> com_n;
  printf("%.8f %.8f\n",0.0,0.0);
  koch(com_n,make_pair(0.0,0.0),make_pair(100.0,0.0));
  printf("%.8f %.8f\n",100.0,0.0);
  return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  double a,b,c;
  cin>>a>>b>>c;
  c=PI*c/180;
  double s,l,h;
  s=a*b*sin(c)/2;
  l=a+b+sqrt(a*a+b*b-2*a*b*cos(c));
  h=2*s/a;
  printf("%.10f\n%.10f\n%.10f\n",s,l,h);
}
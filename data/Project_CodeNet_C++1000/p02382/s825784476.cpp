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
  int n;
  cin>>n;
  vector<double>a(n);
  vector<double>b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  vector<double>in(n);
  rep(i,n)in[i]=abs(a[i]-b[i]);
  double x=0,y=0,c=0,d=0;
  rep(i,n){
    x+=in[i];
    y+=in[i]*in[i];
    c+=in[i]*in[i]*in[i];
    if(d<in[i])d=in[i];
  }
  y=sqrt(y);
  c=pow(c,1.0/3.0);
  printf("%.10f\n%.10f\n%.10f\n%.10f\n",x,y,c,d);
}
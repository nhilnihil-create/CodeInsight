#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
double pi=3.141592653589;
int main() {
  cout<<setprecision(10);
  double a,b,x; cin>>a>>b>>x;
  double t;
  if(2*x>a*a*b){
    t=2*(b/a-x/(a*a*a));
  }
  else{t=a*b*b/(2*x);}
  cout<<atan(t)*180/pi;
}
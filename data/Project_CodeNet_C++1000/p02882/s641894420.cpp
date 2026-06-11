#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  double a,b,x;cin >> a >> b >> x;
  if( 2*x <= a*a*b ){
    double c = 2.0*x/a/b;
    cout << fixed << setprecision(10) << atan(b/c)/(2*M_PI)*360.0;
  }else{
    double c = 2.0*b-2.0*x/a/a;
    cout << fixed << setprecision(10) << atan(c/a)/(2*M_PI)*360.0;
  }
  cout << endl;
  return 0;
}

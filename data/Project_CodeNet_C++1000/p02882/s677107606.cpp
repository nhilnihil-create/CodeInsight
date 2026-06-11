#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
const double PI=3.14159265358979323846;
int main() {
  double a,b,x; cin >> a >> b >> x;
  x/=a;
  if(x > (a*b)/2){
  double tantheta = 2*(a*b - x) / (a*a);
  double theta = atan(tantheta);
  theta *= (180 / PI);
  printf("%.16f", theta);
  }
  else{
  double tantheta = b*b / (2*x);
  double theta = atan(tantheta);
  theta *= (180 / PI);
  printf("%.16f", theta);
  }
    
}
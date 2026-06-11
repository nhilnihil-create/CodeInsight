#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;
const double PI = acos(-1);

int main(){
  double a,b,h,m; cin>>a>>b>>h>>m;
  double thetaH = double(h*30+(m/2));
  double thetaM = double(6*m);
  double rad = PI * abs(thetaH-thetaM) / (double)180;
  double ans = double(sqrt(a*a + b*b - 2.0*a*b*cos(rad)));
  cout << setprecision(10) << ans << endl;
}
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  double a,b,x;
  cin>>a>>b>>x;
  
  if(2*x==a*a*b) cout<<fixed << setprecision(15) <<atan(b/a)*180/pi<<endl;
  else if(2*x>a*a*b) cout<<fixed << setprecision(15) <<atan(2*(a*a*b-x)/a/a/a)*180/pi<<endl;
  else cout<<fixed << setprecision(15) <<atan(a*b*b/2/x)*180/pi<<endl;
  
  return 0;
}
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ll long long
#define MOD 1000000007
#define MAX 100010
#define aout(a) REP(i,sizeof(a)) cout << a[i] << " "; cout << endl;
#define vout(v) REP(i,v,size()) cout << v[i] << " "; cout << endl;
using namespace std;
using Graph = vector<vector<int>>;
#define PI 3.1415926535897932384
 
int main(){
  double a,b,h; cin>>a>>b>>h;
  double m; cin>>m;
  double shi1,shi2;
  double hh = h + (m / 60);
  shi1 = 360 * hh / 12;
  shi2 = 360 * m / 60;
  double shi = abs(shi1 - shi2);
  if(shi > 180) shi = 360-shi;
  double ans = a*a + b*b - 2*a*b*cos(2*PI*shi/360);
  cout << fixed << setprecision(11) << sqrt(ans);
}
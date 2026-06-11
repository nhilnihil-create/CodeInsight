#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  double a, b, h, m;
  cin >>a>>b>>h>>m;
  double deg=abs(h*30+0.5*m-6*m)/360*2*PI;
  double ans = sqrt(a*a+b*b-2*a*b*cos(deg));
  printf("%.10f\n", ans);
  return 0;
}
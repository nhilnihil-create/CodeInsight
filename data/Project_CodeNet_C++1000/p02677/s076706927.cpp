#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  double a, b, h, m;
  cin >> a>> b>> h >>m;

  double zi=2*M_PI*(h+m/60.0)/12.0;
  double hun=2*M_PI*m/60.0;
  double theta;
  double costh=cos(zi-hun);
  double ans=sqrt(a*a+b*b-2*a*b*costh);
  cout << fixed << setprecision(11) <<  ans << endl;
  return 0;
}

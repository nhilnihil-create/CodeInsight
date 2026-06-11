#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
#define PI 3.141592653589793

double RadianToDegree(double radian){
  return radian * 180.0 / PI;
 }

int main()
{
  double a, b, x;
  cin >> a >> b >> x;
  if(x>=(a*a*b)/2.0){
    cout << fixed << setprecision(10) << RadianToDegree(atan((2.0*a*a*b-2.0*x)/(a*a*a))) << endl;
  }else{
    cout << fixed << setprecision(10) << RadianToDegree(atan((a*b*b)/(2.0*x))) << endl;
  }
}
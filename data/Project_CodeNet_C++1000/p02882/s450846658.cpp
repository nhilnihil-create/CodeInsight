#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  double a, b, x; cin >> a >> b >> x;
  double s = x / a;
  bool flag = s >= (a * b) / 2;

  auto area = [&](double th, bool flag){
      double dgree = th * PI / 180.0;
    if(flag){
      return (a * b) - (a *(a * tan(dgree))/2) >= s;
    } else {
      return b * (b /tan(dgree)) / 2 >= s;
    }
  };

  double ok = 0;
  double ng = 91;
  while(ng - ok > 0.0000001){
    double th = (ok + ng) / 2;
    if(area(th, flag)) ok = th;
    else ng = th;
  }

  printf("%.10f\n", ok);

  return 0;
}

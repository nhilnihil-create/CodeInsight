#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define P pair<ll, ll>
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int 
main()
{
  double a, b, x; cin >> a >> b >> x;
  double s = x / a;
  cout << fixed << setprecision(10);
  if(s >= a * b / 2){
    double h = (2 * (a * b - s)) / a;
    cout << atan2(h, a)* 180 / PI << endl;
  } else {
    double h = (2 * s) / b;
    cout << atan2(b, h) * 180 / PI << endl;
  }

}

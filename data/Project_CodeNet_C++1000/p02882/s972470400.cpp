#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

static const double PI = 3.141592653589793238;


int main(){
  double a, b, x;
  cin >> a >> b >> x;
  if(x == a*a*b){
    cout << 0 << endl;
    return 0;
  }

  if (2*x == a*a*b){
    cout << 45 << endl;
    return 0;
  }

  if(2*x < a*a*b){
    //x < a*a*b*1/2 (半分以下のとき)
    double y = 2*x/(a*b);
    //double th = arctan(y/b);
    //y/b = 2*x/a
    double th_rad = 2*x/(a*b*b);
    //cout << th_rad << endl;
    double th = atan(th_rad);
    //cout << th << endl;
    cout << setprecision(12) <<90-th*180.0/PI<< endl;
    return 0;
  }

  //x > a*a*b*1/2 (半分以下のとき)
  if(2*x > a*a*b){
    x -= a*a*b;
    //double y = 2*x/(a*a);
    //double th_rad = arctan(a/y);
    double th_rad = (a*a*a)/(2*x);
    //double th_rad = (2*x)/(a*a*a);

    double th = atan(th_rad);
    //cout << th << endl;
    cout << setprecision(12) <<90+th*180.0/PI<< endl;
    return 0;
}



  return 0;

}
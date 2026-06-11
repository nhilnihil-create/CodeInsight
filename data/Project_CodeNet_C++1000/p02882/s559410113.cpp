#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  double a, b, x;
  cin >> a >> b >> x;
  if(x >= a*a*b/2){
    double ans = atan(a*a*a/2/(a*a*b-x));
    double hennkann = 180/acos(-1);
    printf("%.10f", 90-ans*hennkann);
  }
  else{
    double ans = atan(a*b*b/2/x);
    double hennkann = 180/acos(-1);
    printf("%.10f", ans*hennkann);
  }
}

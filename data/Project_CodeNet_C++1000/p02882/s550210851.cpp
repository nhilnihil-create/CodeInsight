#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

const double pi = 3.1415926535;

int main(){
  double a, b, x;
  cin >> a >> b >> x;
  double V = a * a * b;
  double M = (double)(a*a*b) / 2;
  double tan;
  if (x <= M) {
    tan = (2*x)/(a*b*b);
  } else {
    tan = (a*a*a)/(2*(V-x));
  }
  double ans = (double)90 - (180 * atan(tan) / pi);
  cout << fixed << setprecision(10) << ans << endl;
}

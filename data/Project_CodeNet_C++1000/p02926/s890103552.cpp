#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int a[100];
int cells[100][100]; // r * c

int main() {
  int N;
  cin >> N;

  vector<double> X(N);
  vector<double> Y(N);

  rep0(i, N) cin >> X[i] >> Y[i];

  double M = 1e5;
  double pi = 3.14159265358979;
  double ans = 0;

  for(double i = 0; i < M; i++) {
    double theta = i / M * 2 * pi;
    double x = cos(theta);
    double y = sin(theta);

    double tempX = 0;
    double tempY = 0;
    rep0(j, N) {
      if (x * X[j] + y * Y[j] > 0) {
        tempX += X[j];
        tempY += Y[j];
      }
    }
    // if(i<10)cout << tempX << SP << tempY << BR;
    ans = max(ans, sqrt(tempX * tempX + tempY * tempY));
  }

  fcout << ans << BR;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

double radi(double n) {
  return n * M_PI / 180;
}

int main()
{
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double hd = h / 12.0 * 360 + (30 * m / 60.0);
  double md = m / 60.0 * 360;
  double hr = radi(hd);
  double mr = radi(md);
  double hx = a * cos(hr);
  double hy = a * sin(hr);
  double mx = b * cos(mr);
  double my = b * sin(mr);
  double ans = sqrt(pow(abs(hx-mx), 2) + pow(abs(hy-my), 2));
  printf("%.10f", ans);
  
   
  return 0;
}
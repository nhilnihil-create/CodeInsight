#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double pi = acos(-1);
  double ans = sqrt(a*a + b*b -2 * a * b * cos((60*h + m) * pi * 11 / 360));
  printf("%.10f",ans);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
ll n,k;
cin >> n >> k;
vector<double> vec(n);
double cnt = 0,ans = 0;
rep(i,n) {
  double a;
  cin >> a;
  double b;
  b = a * (a +1) / 2;
  b /= a;
  vec.at(i) = b;
}
rep(i,k) cnt += vec.at(i);
for (int i = k;i <= n;i++) {
  if (cnt > ans) {
    ans = cnt;
  }
  cnt -= vec.at(i-k);
  if (i != vec.size()) cnt += vec.at(i);
  }
  
printf("%.10f\n" ,ans);

return 0;
}


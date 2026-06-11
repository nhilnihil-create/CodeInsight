#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <complex>
#include <iomanip>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define vvd std::vector<std::vector<long double> >
#define MODs 1000000007;
typedef long long int ll;
typedef long double ld;
using namespace std;

long double rad(long double r){
  if(r >= 0) return (r/M_PI)*180;
  else return ((M_PI + r)/M_PI)*180 + 180;
}
int main(int argc, char const *argv[]) {
  ld N, a, b, ans = 0;
  std::cin >> N;
  vvd T = vv(2*N, 3, 0, ld);
  for(ld i=0;i<N;i++){
    std::cin >> a >> b;
    T[i][0] = rad(arg(complex<ld>(a, b)));
    T[N+i][0] = T[i][0] + 360.0;
    T[i][1] = T[N+i][1] = a, T[i][2] = T[N+i][2] = b;
  }
  sort(T.begin(), T.end());
  for(ld i=0;i<N;i++){
    ld x = 0, y = 0;
    for(ld j=i;j<2*N&&T[j][0]-T[i][0]<=180;j++){
      x += T[j][1], y += T[j][2];
      ans = max(ans, sqrt(x*x + y*y));
    }
  }
  std::cout << fixed << setprecision(20) << ans << '\n';
  return 0;
}

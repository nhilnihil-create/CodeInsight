#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int A,B,H,M;
  cin >> A >> B >> H >> M;
  double theta = abs(H*30+M/2.0-6.0*M);
  double ans = sqrt(A*A+B*B-2*A*B*cos(theta/180.0*M_PI));
  printf("%.20f\n",ans);
}

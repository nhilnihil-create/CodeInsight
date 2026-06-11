#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll W,H,x,y;
  cin >> W >> H >> x >> y;
  int a=0;
  if(W==2*x && H==2*y) a=1;
  printf("%lf %d\n", W*H/2.0,a);
}

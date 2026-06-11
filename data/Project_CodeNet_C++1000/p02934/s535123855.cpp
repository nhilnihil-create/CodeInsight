#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a;
  cin >> a;
  int b[a],lcm,sum=0;
  rep(i,a){
    cin >> b[i];
    if(i==0) lcm = b[i];
    lcm = lcm*b[i]/__gcd(lcm,b[i]);
  }
  rep(i,a){
    sum += lcm/b[i];
  }
  double ans1 = lcm,ans2=sum;
  cout << ans1/ans2;
}

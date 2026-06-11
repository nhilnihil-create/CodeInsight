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
  int a,sum,tmp,ans1,ans2;
  cin >> a;
  vi num(a+1,0);
  rep(i,a){
    cin >> tmp;
    sum += tmp;
    num.at(i+1) = tmp + num.at(i);
  }
  ans1 = sum;
  rep(i,a+1){
    tmp = num.at(i)*2;
    ans1 = min(ans1,abs(tmp-sum));
    ans2 = ans1;
  }
  cout << ans2;
}
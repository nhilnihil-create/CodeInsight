#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 1; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  ll a;
  cin >> a;
  ll ans1,ans2;
  rep(i,sqrt(a)+1){
    if(a%i==0){
       ans1 = i;
       ans2 = a/i;
    }
  }
  cout << ans1+ans2-2;
}
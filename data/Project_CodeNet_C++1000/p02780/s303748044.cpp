#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> sum(n+1, 0);
  rep(i, n){
    cin >> p[i];
    sum[i+1] = sum[i] + p[i];
  }
  int maxNum = 0;
  int ind = 0;
  rep(i, n-k+1){
    int num = sum[i+k] - sum[i];
    if (maxNum < num){
      maxNum = num;
      ind = i;
    }
  }
  double ans = 0.0;
  rep(i, k){
    ans += (p[ind+i] + 1.0) / 2.0;
  }
  cout << fixed << setprecision(10) << ans << endl;
  
  return 0;
}
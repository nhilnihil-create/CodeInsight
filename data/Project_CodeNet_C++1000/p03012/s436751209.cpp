#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  int sum = 0;
  rep(i, n){
    cin >> w[i];
    sum += w[i];
  }
  int ans = 1000;
  int temp = 0;
  rep(i, n){
    temp += w[i];
    ans = min(ans, abs(sum - 2 * temp));
  }
  cout << ans << endl;
  
  return 0;
}
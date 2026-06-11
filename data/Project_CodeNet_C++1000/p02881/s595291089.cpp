#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  long long n;
  long long ans = 1e13;
  cin >> n;

  // vector<pair<long long, long long>> res;
  vector<long long> sum;
  for(long long i = 1; i * i <= n; i++){
    // cout << i << endl;
    if(n%i == 0){
      // res.push_back(make_pair(i, n/i));
      sum.push_back(i + n / i);
    }
  }
  for(int i = 0; i < sum.size(); i++){
    ans = min(ans, sum[i]);
  }
  cout << ans - 2 << endl;

  return 0;
}
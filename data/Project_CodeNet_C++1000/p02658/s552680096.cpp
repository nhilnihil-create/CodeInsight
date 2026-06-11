#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int64_t ans=1,threshold = 1000000000000000000,th_check;
  th_check = threshold;
  vector<int64_t> v(n);
  for(int i=0; i<n; i++){
    cin >> v.at(i);

    if(v.at(i) == 0){
      ans = 0;
      cout << 0 << endl;
      return 0;
    }
  }
  for(auto x: v){
    th_check /= x;
    if(th_check == 0){
      cout << -1 << endl;
      return 0;
    }
    ans *= x;
  }
  if(ans > threshold){
      ans = -1;
    }
  cout << ans << endl;
}
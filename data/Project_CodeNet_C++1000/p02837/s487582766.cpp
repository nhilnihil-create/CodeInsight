#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int BitNum(int n){
  int tmp = n;
  int res = 0;
  while(tmp > 0){
    if(tmp % 2 == 1) res ++;
    tmp /= 2;
  }
  return res;
}

int main(){
  int n;
  const int max_n = 15;
  int a[max_n + 1];
  vector<vector<int>> x(max_n+1);
  vector<vector<int>> y(max_n+1);

  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    for(int j = 0; j < a[i]; j++) {
      int b,c;
      cin >> b >> c;
      b--;
      x.at(i).push_back(b);
      y.at(i).push_back(c);
    }
  }

  // bit full search
  bool flag = 0;
  int ans = 0;
  for(int bit = 0; bit < (1<<n); bit++){
    flag = 0;
    // cout << "bit = " << bit << endl;
    for(int i = 0; i < n; i++){
      if(bit&(1<<i)){
        // cout << "person " << i << " = honest" << endl;
        // person i is the honest man
        // check the remark of person i
        for(int j = 0; j < a[i]; j++){
          if((y[i][j] == 1) && (((1<<x[i][j])&bit) > 0)) continue;
          if((y[i][j] == 0) && (((1<<x[i][j])&bit) == 0)) continue;
          // cout << "anser" << j << " = uncorrect" << endl;
          flag = 1;
        }
      }
    }
    if(flag == 0){
      // all remark is correct.
      // cout << bit << endl;
      ans = max(ans, BitNum(bit));
    }
  }

  cout << ans << endl;

  return 0;
}
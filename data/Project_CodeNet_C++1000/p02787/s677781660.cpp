#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001001001;
template<class T> bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int dp[10050];

int main(){
  int h, n; cin >> h >> n;
  vector<int> a(n), b(n);
  for(int i = 1; i <= h + 10; i++) dp[i] = MAX;
  for(int i = 0; i < n; i++){
    cin >> a.at(i) >> b.at(i);
    dp[a[i]] = b[i];
  }
  for(int i = 1; i <= h; i++){
    for(int j = 0; j < n; j++){
      if(i-a[j] > 0){
        chmin(dp[i], dp[i-a[j]] + b[j]);
      }
      else{
        chmin(dp[i], b[j]);
      }
    }
  }
  cout << dp[h] << endl;
}
    
  

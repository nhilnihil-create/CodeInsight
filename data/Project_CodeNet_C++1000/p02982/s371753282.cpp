#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, n)rep(j, d) cin >> x[i][j];
  int ans = 0;
  rep(i, n-1)rep2(j, i+1, n){
    int num = 0;
    rep(k, d){
      num += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
    }
    int snum = sqrt(num);
    if (snum * snum == num) ans++;
  }
  cout << ans << endl;
  
  return 0;
}
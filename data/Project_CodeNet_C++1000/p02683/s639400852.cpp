#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int inf = 1000000000;
  int n, m, x;
  cin >> n >> m >> x;
  int c[n], a[n][m], r[m];
  rep(i, n){
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  int ans = 1000000000;
  for(int i = 0; i < (1 << n); i++){
    rep(j, m) r[j] = 0;
    int y = i;
    int cnt = 0;
    int sum = 0;
    while(y > 0){
      if(y & 1){

        sum += c[cnt];
        rep(j, m) r[j] += a[cnt][j];
      }
      y /= 2;
      cnt++;
    }
    int ok = 0;
    rep(j, m) {
      if(r[j] >= x) ok++;
    }
    if(ok == m) ans = min(ans, sum);
  }
  cout << (ans != 1000000000 ? ans : -1) << endl;
        

  return 0;
}
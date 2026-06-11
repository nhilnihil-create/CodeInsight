#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  int ans = 2020;
  if(m - n >= 2018) {
    ans = 0;
  }
  else{
    rep(i, m - n){
      for(int j = i + 1; j < m - n + 1; j++){
        ans = min(ans, (((n + i) % 2019) * ((n + j) % 2019) % 2019));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
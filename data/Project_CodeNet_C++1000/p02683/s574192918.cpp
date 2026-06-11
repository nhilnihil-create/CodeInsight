#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[15][15];
int c[15];
int main(){
  int n, m, x;
  cin >> n >> m >> x;
  for(int i = 0; i < n; i++){
    cin >> c[i];
    for(int j = 0; j < m; j++) cin >> a[i][j];
   }
   
   int ans = 1001001001;
    for (int bit=0; bit<(1<<n); bit++){
      int cost = 0;
      int sk[15] = {0};
      bool hantei = true;
        for (int i = 0; i < n; i++){
            if (bit&(1ull<<i)){
              cost += c[i];
              for(int j = 0; j < m; j++) sk[j] += a[i][j];
          }
        }
        for(int j = 0; j < m; j++){
          if(sk[j]>=x) continue;
          else hantei = false;
        }
        if(hantei) ans = min(ans, cost);
    }
   if(ans != 1001001001)cout << ans << endl;
   else cout << -1 << endl;
  return 0;
}
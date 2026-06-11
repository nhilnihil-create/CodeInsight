#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<long long> x(N),y(N);
  for(int i = 0;i < N;i++) {
    cin >> x.at(i) >> y.at(i);
  }

  int ans = 10000;
  for(int i = 0;i < N;i++) {
    for(int j = 0;j < N;j++) {
      if(i == j) continue;
      long long p = x.at(j)-x.at(i),q = y.at(j)-y.at(i);
      int num = 0;
      for(int k = 0;k < N;k++) {
        for(int l = 0;l < N;l++) {
          if(k == l) continue;
          if(x.at(l)-x.at(k) == p && y.at(l)-y.at(k) == q) num++;
        }
      }
      ans = min(ans,N-num);
    }
  }
  
  if(N != 1) cout << ans << endl;
  else cout << 1 << endl;
}

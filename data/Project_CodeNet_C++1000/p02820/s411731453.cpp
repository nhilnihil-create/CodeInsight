#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N, K, R, S, P; cin >> N >> K >> R >> S >> P;
  string T; cin >> T;
  
  int ans = 0;
  rep(k, K) {
    int t = 1;
    for(int i=k; i<N; i+=K) {
      if(i+K >= N) {
        if(T[i] == 'r') ans += (t+1)/2*P;
        if(T[i] == 's') ans += (t+1)/2*R;
        if(T[i] == 'p') ans += (t+1)/2*S;
        break;
      }
      if(T[i] == T[i+K]) t++;
      else {
        if(T[i] == 'r') ans += (t+1)/2*P;
        if(T[i] == 's') ans += (t+1)/2*R;
        if(T[i] == 'p') ans += (t+1)/2*S;
        t = 1;
      }
      
    }
  }
  
  cout << ans << endl;
        

}

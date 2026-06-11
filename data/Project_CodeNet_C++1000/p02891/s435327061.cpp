#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  string s; cin >> s;
  lint K; cin >> K;
  lint N = s.size();
  bool judge = true;
  for(lint i = 1; i < N; i++){
    if(s[i] != s[i - 1]) judge = false; 
  }
  if(judge && N % 2 == 1){
    if(K % 2 == 0) cout << N * (K / 2) << endl;
    else cout << N * ((K - 1) / 2) + N / 2 << endl;
  }
  else{
    string t;
    t = s; t += s;
    lint cs = 0, ct = 0;
    for(lint i = 1; i < N; i++){
      if(s[i] == s[i - 1]) {
        cs++; i++;
      }
    }
    for(lint i = 1; i < t.size(); i++){
      if(t[i] == t[i - 1]) {
        ct++; i++;
      }
    }
    lint ans = cs + (ct - cs) * (K - 1);
    cout << ans << endl;
  }
}
#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N, P; cin >> N >> P;
  string s; cin >> s;
  lint ans = 0;
  if(P == 2 || P == 5){
    for(lint i = 0; i < N; i++){
      if((s[N - i - 1] - '0') % P == 0) ans += N - i;
    }
  }
  else{
    map<lint, lint> MAP;
    MAP[0]++;
    lint num = 0, ten = 1;
    for(lint i = 0; i < N; i++){
      ten = (10 * ten) % P;
      num = num + (s[N - i - 1] - '0') * ten;
      num %= P;
      MAP[num]++;
    }
    for(auto value : MAP){
      ans += value.second * (value.second - 1) / 2;
    }
  }
  cout << ans << endl;
}
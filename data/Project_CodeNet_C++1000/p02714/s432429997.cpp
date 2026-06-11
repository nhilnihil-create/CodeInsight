#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  LL N;
  string S;
  cin >> N >> S;
  LL R = count(begin(S), end(S), 'R');
  LL ans = 0;
  for(auto g=0; g<N; ++g) {
    for(auto b=0; b<N; ++b) {
      if(S[g] != 'G') continue;
      if(S[b] != 'B') continue;
      ans += R;
      auto d = abs(g-b);
      for(auto r: {(g+b)/2, min(g,b)-d, max(g,b)+d}) {
        vector<LL> i = {r, g, b};
        sort(begin(i), end(i));
        if(S[r] != 'R') continue;
        if(i[2]-i[1] != i[1]-i[0]) continue;
        if(i[0]<0 || N-1<i[2]) continue;
        --ans;
      }
    }
  }
  cout << ans << endl;
}

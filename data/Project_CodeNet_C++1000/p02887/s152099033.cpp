#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  S.push_back('#');
  int ans = 0;
  for(size_t i = 0; i + 1 < S.size(); i++) {
      // 数えるのは境界線の数だけでいい
      if(S[i] != S[i+1]) ans++;
  }
  cout << ans << endl;
}

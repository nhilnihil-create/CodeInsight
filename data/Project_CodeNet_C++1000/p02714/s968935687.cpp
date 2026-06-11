#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  string S; cin >> S;
  
  unordered_map<int,int> R, G, B;
  rep(i, N) {
    if(S[i] == 'R') R[i]++;
    else if(S[i] == 'G') G[i]++;
    else if(S[i] == 'B') B[i]++;
  }

  int ans = R.size()*G.size()*B.size();
  
  for(auto r : R) for(auto g : G) {
    int a = r.first, b = g.first;
    if(a < b) swap(a, b);
      if(B[a+(a-b)] > 0) ans--;
      if(B[b-(a-b)] > 0) ans--;
      if((a-b)%2 == 0 && B[(a+b)/2] > 0) ans--;
  }
  cout << ans << endl;

}

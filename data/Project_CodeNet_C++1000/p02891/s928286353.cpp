#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  string S; cin >> S;
  int K; cin >> K;
  
  vector<int> vec(0);
  int k = 0;
  char c = S[0];
  rep(i, S.size()) {
    if(S[i] == c) k++;
    else {
      vec.push_back(k);
      k = 1;
      c = S[i];
    }
    if(i == S.size()-1) vec.push_back(k);
  }
  
  //rep(i, vec.size()) cout << vec[i] << endl;
  
  int ans = 0;
  if(S[0] == S[S.size()-1]) {
    if(vec.size() > 1) {
      rep(i, vec.size()-2) {
        ans += (vec[i+1]/2)*K;
      }
      ans += ((vec[0]+vec[vec.size()-1])/2)*(K-1);
      ans += vec[0]/2 + vec[vec.size()-1]/2;
    } else {
      ans += (vec[0]*K)/2;
    }
  } else {
    rep(i, vec.size()) {
      ans += (vec[i]/2)*K;
    }
  }
  
  cout << ans << endl;
}
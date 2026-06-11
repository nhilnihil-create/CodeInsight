#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<vector<int>>c(10,vector<int>(10));
  rep2(i,1,n+1){
    string s=to_string(i);
    c[s.at(0)-'0'][s.at(s.size()-1)-'0']++;
  }
  int ans=0;
  rep(i,10){
    rep(j,10){
      ans+=c[i][j]*c[j][i];
    }
  }
  cout<<ans<<endl;
}
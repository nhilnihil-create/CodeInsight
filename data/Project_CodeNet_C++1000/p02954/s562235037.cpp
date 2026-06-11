#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  string s;
  cin >> s;
  int n = int(s.size());
  vector<int> ans(n);
  rep(ri,2){
    int cnt = 0;
    rep(i,n){
      if(s[i]=='R'){
        cnt++;
      }else{
        ans[i] += cnt/2;
        ans[i-1] += (cnt+1)/2;
        cnt = 0;
      }
    }
    reverse(ans.begin(),ans.end());
    reverse(s.begin(),s.end());
    rep(i,n){
      if(s[i]=='R'){
        s[i] = 'L';
      }else{
        s[i] = 'R';
      }
    }
  }
  rep(i,n){
    cout << ans[i] << endl;
  }
  return 0;

}
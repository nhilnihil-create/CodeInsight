#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(){
  string s,t; cin >> s >> t;
  int sn = s.size(), tn = t.size();
  int ans = t.size();
  for(int i = 0; i <= sn - tn; i++){
    int count = 0;
    for(int j = 0; j < tn; j++){
      if(s[j+i] != t[j]){
        count++;
      }
    }
    ans = min(ans,count);
  }
  cout << ans << endl;
  return 0;
}

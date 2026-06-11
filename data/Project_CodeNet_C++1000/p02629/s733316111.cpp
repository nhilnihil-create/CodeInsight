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

int main(void){
  ll n; cin >> n;
  vector<char> ans;
  while(n){
    n--;
    ans.push_back('a' + n%26);
    n/=26;
  }
  reverse(ans.begin(),ans.end());
  for(int i = 0; i < ans.size(); i++){
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}

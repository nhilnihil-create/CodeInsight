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
  int x,n; cin >> x >> n;
  if(n == 0){
    cout << x << endl;
    return 0;
  }
  int p[n];
  int dif = 0;
  rep(i,n) cin >> p[i];
  while(1){
    rep(i,n){
      if(x-dif == p[i]) break;
      else if(i == n-1){
        cout << x - dif << endl;
        return 0;
      }
    }
    rep(i,n){
      if(x + dif == p[i]) break;
      else if(i == n-1){
        cout << x + dif << endl;
        return 0;
      }
    }
    dif++;
  }
  return 0;
}

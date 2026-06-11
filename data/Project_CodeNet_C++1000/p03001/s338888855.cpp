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
  long double w,h,x,y; cin >> w >> h >> x >> y;
  cout << w*h/2;
  if(x == w/2 && y == h/2) cout << " " << 1 << endl;
  else cout << " " << 0 << endl;
  return 0;
}

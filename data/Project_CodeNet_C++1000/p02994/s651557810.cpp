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
  int n,L;
  cin >> n >> L;
  vector<int> a(n);
  rep(i,n) a[i] = L+i;
  int s = 0;
  rep(i,n) s += a[i];
  int ans = mod;
  rep(i,n){
    int p = s;
    p -= a[i];
    if(abs(ans-s)>abs(s-p)) ans = p;
  }
  cout << ans << endl;
  return 0;
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  if(k >= 5000){
    rep(i, n) cout << n << " ";
    cout << ln;
  }else{
    rep(i, k){
      vector<int> plus(n), minus(n);
      rep(j, n){
        int s = max(0, j-A[j]), t = min(n-1, j+A[j]);
        plus[s]++; minus[t]++;
      }
      int cnt = 0;
      rep(j, n){
        cnt += plus[j];
        A[j] = cnt;
        cnt -= minus[j];
      }
    }
    rep(i, n){
      cout << A[i] << " ";
    }cout << ln;
  }
}

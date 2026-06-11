#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  int N; cin >> N;
  int ans=0;
  v<int> A(N);
  rep(i,N) cin >> A[i];
  rep(i,60){
    int x=0;
    rep(j,N){
      if(A[j]>>i & 1) ++x;
    }
    int now=x*(N-x)%MOD;
    rep(j,i){
      now=now*2%MOD;
    }
    ans+=now%MOD;
  }
  cout << ans%MOD << endl;
  return 0;
}

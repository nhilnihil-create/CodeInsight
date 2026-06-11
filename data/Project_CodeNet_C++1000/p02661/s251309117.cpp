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
  v<int> A(N),B(N);
  rep(i,N){
    cin >> A[i] >> B[i];
  }
  sort(ALL(A));
  sort(ALL(B));
  if(N%2==0){
    cout << (B[N/2]+B[N/2-1])-(A[N/2]+A[N/2-1])+1 << endl;
  }
  else{
    cout << B[(N+1)/2-1]-A[(N+1)/2-1]+1 << endl;
  }
  return 0;
}

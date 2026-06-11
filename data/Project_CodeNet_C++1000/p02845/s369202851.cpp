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
  unordered_map<int,int> mp;
  int ans=1;
  rep(i,N){
    int A; cin >> A;
    mp[A]++;
    if(A==0){
      ans=(ans*(4LL-mp[A]))%MOD;
    }
    else{
      ans=(ans*(mp[A-1]-mp[A]+1LL))%MOD;
    }
  }
  cout << ans%MOD << endl;
}

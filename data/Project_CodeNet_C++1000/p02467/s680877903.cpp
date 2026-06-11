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
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
/*素数判定*/int isPrime(int n){if(n<2){return 0;}for(int i=2; i*i<=n; i++){if(n%i==0){return 0;}}return 1;}

signed _main() {
  int n; cin >> n;
  int N=n;
  v<int> ans;
  while(n>1){
    if(isPrime(n)){
      ans.push_back(n);
      break;
    }
    for(int i=2;i*i<=N;i++){
      if(n%i==0){
        ans.push_back(i);
        n/=i;
        break;
      }
    }
  }
  sort(ans.begin(),ans.end());
  cout << N << ": ";
  rep(i,ans.size()-1) cout << ans[i] << " ";
  cout << ans[ans.size()-1] << endl;
}


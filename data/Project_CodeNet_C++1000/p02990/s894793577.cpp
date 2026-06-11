#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vector<vector<ll>> ncr(n+1,vector<ll>(n+1));
  ncr[0][0] = 1;
  rep(i,n){
    rep(j,i+1){
      ncr[i][j] %= MOD;
      ncr[i+1][j] += ncr[i][j];
      ncr[i+1][j+1] += ncr[i][j];
    }
  }
  rep(i,k){
    cout << ncr[n-k+1][i+1]*ncr[k-1][i]%MOD << endl;
  }
  cout << "\n";
  return 0;
}

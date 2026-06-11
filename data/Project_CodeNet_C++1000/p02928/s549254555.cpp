#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  const int MOD = 1e9+7;
  ll n,k; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];
  ll ans = 0, cnt1 = 0, cnt2 = 0;
  rep(i,n){
    rep(j,n){
      if(a[i] > a[j]){
        if(i < j) cnt1++;
        cnt2++;
      }
    }
  }
  ans = cnt1*k;
  ans %= MOD;
  ans += k*(k-1)/2%MOD*cnt2;
  ans %= MOD;
  cout << ans;
  cout << "\n";
  return 0;
}

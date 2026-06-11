#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

ll sum(ll l, ll r){
   return (r+l)*(r-l+1)/2;
 }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  const int MOD = 1e9+7;
  ll ans = 0;
  for(int i = k; i <= n+1; i++){
    ll l = sum(0,i-1), r = sum(n-i+1,n);
    ans += r-l+1;
    ans %= MOD;
  }
  cout << ans;
  cout << "\n";
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  
  ll all_time = 0;
  rep(i,m) all_time += b[i];
  int b_cnt = m;
  int ans = 0;
  rep(i,n+1){
    while(b_cnt>0 && all_time>k){
      b_cnt--;
      all_time -= b[b_cnt];
    }
    if(all_time > k) break;
    ans = max(ans, b_cnt+i);
    if (i==n) break;
    all_time += a[i];
  }
  cout << ans << endl;
}
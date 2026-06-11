#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5005;
int a[N];

int n;
void solve(){
  int m, x, mod;
  cin >> m >> x >> mod;
  int ans = m - 1;
  int cnt;
  ll sum = (x%mod);
  ll cur;
  for(int i = 0 ; i < n; i ++ ){
    cnt = ((m-1)/n) + (((m-1)%n)>i);
    if(a[i] % mod == 0){
      ans -= ((m-1)/n) + (((m-1)%n)>i);
    }
    sum += cnt*1ll*(a[i]%mod);
  }
  ans -= sum/mod;
  cout << ans << "\n";
}

int main(){
  fastIO;
  int q;
  cin >> n >> q;
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
  }
  for(int t = 0 ;t < q; t ++ ) solve();
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector < ll > a;
ll n, m, v, p;

bool check(ll x){
  if(x < p) return true;
  ll cnt = m;
  cnt += (p - 1) * m;
  cnt += (n - x - 1) * m;
  for(int i = p - 1; i < x; i++){
    if(a[x] + m - a[i] < 0) return false;
    cnt += (a[x] + m - a[i]);
  }
  if(cnt >= m * v) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> n >> m >> v >> p;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end(), greater < ll > ());

  ll lo = 0, hi = n - 1, ans = LLONG_MIN;
  while(lo <= hi){
    ll mid = (hi - lo) / 2 + lo;
    if(check(mid)){
      lo = mid + 1;
      ans = max(ans, mid);
    }else{
      hi = mid - 1;
    }
  }

  cout << ans + 1 << endl;
}

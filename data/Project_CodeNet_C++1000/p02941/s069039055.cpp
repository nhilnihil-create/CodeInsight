#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  rep(i,N) cin>>A[i];
  rep(i,N) cin>>B[i];

  ll ans = 0;
  queue<ll> q; // {index}
  rep(i,N) q.push(i);

  while(!q.empty()){
    ll i = q.front(); q.pop();
    ll a = B[(N+i-1)%N];
    ll b = B[(N+i)%N];
    ll c = B[(N+i+1)%N];
    // printf("%d %d %d %d\n",i,a,b,c);

    if (b == A[i]) { // B[i]がA[i]に一致済み
      continue;
    } else if (b-A[i] >= 0 && (b-A[i])%(a+c) == 0) { // B[i]をA[i]に一致させれる
      ans += (b-A[i]) / (a+c);
      B[i] = A[i];
      q.push((N+i+1)%N);
      q.push((N+i-1)%N);
    } else if (b-a-c >= A[i]) { // B[i] をA[i]に近付けられる
      ll t = (b-A[i])/(a+c);
      ans += t;
      B[i] = B[i] - t * (a+c);
      q.push((N+i+1)%N);
      q.push((N+i-1)%N);
    } else{
      continue;
    }
  }

  if (A==B) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

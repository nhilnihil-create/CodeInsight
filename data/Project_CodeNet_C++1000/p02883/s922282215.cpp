#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

ll n,k;
vector<ll> a;
vector<ll> f;

bool solve(ll mid,ll tmp = k){
  rep(i,n){
    if(a[i]*f[i] > mid){
      ll target = a[i]*f[i] - mid;
      tmp -= (target + f[i] - 1)/f[i];
    }
  }
  return tmp >= 0;
}

int main(){
  cin >> n >> k;
  a.resize(n);
  f.resize(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(a);
  sort(f);
  reverse(f);
  ll ok = (ll)pow(10,18)+1;
  ll ng = -1;
  while(abs(ok - ng) > 1){
    ll tmp = k;
    ll mid = (ok + ng) / 2;
    if (solve(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}

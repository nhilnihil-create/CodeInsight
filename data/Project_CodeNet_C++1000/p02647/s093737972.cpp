//author: Harsh Nema
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define maxN 100007
using namespace std;
int main(){
  fastio;
  ll n = 0, k = 0;
  cin>>n>>k;
  vector<ll>a(n+1,0);
  for(ll i = 0; i<n; ++i) cin>>a[i];
  vector<ll>b(n+1,0);
  while(k--){
    for(ll i = 0; i <= n ;++i) b[i]=0;
    for(ll i = 0; i < n; ++i){
      ll l = max(0ll, i - a[i]);
      ll r = min(i + a[i], n - 1);
      ++b[l];
      --b[r + 1];
    }
    bool different = false;
    for(ll i = 0; i < n; ++i){
      different |= (a[i] != b[i]);
      a[i] = b[i];
      b[i+1] += b[i];
    }
    if(!different) break;
  }
  for(ll i = 0; i < n; ++i) cout<<b[i]<<" ";
  return 0;
}

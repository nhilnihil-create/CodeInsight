#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  vector<ll> a(m), b(m);
  rep(i,m) cin >> a[i] >> b[i];
  vector<bool> hantei(n, true);
  rep(i,m){
    if(h[a[i]-1] < h[b[i]-1]) hantei[a[i]-1] = false;
    else if(h[a[i]-1] > h[b[i]-1]) hantei[b[i]-1] = false;
    else{
      hantei[a[i]-1] = false;
      hantei[b[i]-1] = false;
    }
  }
  int ans=0;
  rep(i,n){
    if(hantei[i]) ans++;
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n;ll k;cin >> n >> k;
  vector<int> a(n),f(n);
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  if(sum <= k){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n) cin >> f[i];
  sort(a.rbegin(),a.rend());
  sort(f.begin(),f.end());

  vector<ll> score(n);
  ll mx = 0;
  rep(i,n) {
    score[i] = ll(a[i])*ll(f[i]);
    mx = max(mx,score[i]);
  }
  ll mi = 0;

  ll temp;
  while(mx-mi>1){
    temp = (mx+mi)/2;
    sum = 0;
    rep(i,n){
      ll upp = max(score[i]-temp,ll(0));
      sum += upp/f[i];
      if(upp%f[i]!=0) sum++;
    }
    if(sum > k) mi = temp;
    else mx = temp;
  }
  cout << mx << endl;
}
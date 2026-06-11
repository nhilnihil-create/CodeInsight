#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  ll mx = 0, cnt;
  rep(i,k) mx += p[i];
  cnt = mx;
  int ansi = 0;
  rep(i,n-k){
    cnt = cnt - p[i] + p[k+i];
    if(mx < cnt) {
      mx = cnt;
      ansi = i+1;
    }
  }
  ll dbans = 0;
  rep(i,k) dbans += p[ansi + i] + 1;
  double ans = dbans;
  ans /= 2;
  printf("%.10f\n", ans);
}

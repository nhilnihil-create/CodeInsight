#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vi a(n);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int cnt = 0;
  ll ans = 0;
  cnt++;
  ans += a.at(0);
  cnt++;
  REP(i,1,n){
    if (cnt == n) break;
    ans += a.at(i);
    cnt++;
    if (cnt == n) break;
    ans += a.at(i);
    cnt++;
    if (cnt == n) break;
  }
  cout << ans << endl;
  return 0;
}

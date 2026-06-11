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

  vi h(n);
  rep(i,n) cin >> h.at(i);
  reverse(h.begin(), h.end());

  int cnt = 0;
  int ans = 0;
  rep(i,n-1){
    if (h.at(i) <= h.at(i+1)) cnt++;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

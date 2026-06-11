#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> h(n);
  REP(i,n){
    int x;
    cin >> x;
    h[i].first = x;
    h[i].second = 1;
  }

  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a; --b;

    if(h[a].first > h[b].first){
      h[b].second = 0;
    }
    if(h[a].first < h[b].first){
      h[a].second = 0;
    }

    if(h[a].first == h[b].first){
      h[a].second = 0;
      h[b].second = 0;
    }

  }

  int ans = 0;
  REP(i,n) ans += h[i].second;

  // cout << endl;
  // 
  // REP(i,n) cout << h[i].first << " " << h[i].second << endl;


  cout << ans << endl;
  return 0;
}

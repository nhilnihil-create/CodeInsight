#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  vector<bool> ok(n, true);
  rep(i, n) cin >> h[i];
  vector<int> ans(n);
  int cnt = 0;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    if(h[a-1] <= h[b-1]) ok[a-1] = false;
    if(h[b-1] <= h[a-1]) ok[b-1] = false;
  }
  rep(i, n){
    if(ok[i]) cnt++;
  }
  cout << cnt << endl;
}

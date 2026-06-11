#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> x(n);
  for(int i=0; i<n; ++i) cin >> x[i].first >> x[i].second;
  sort(x.begin(),x.end());
  queue<P> que;
  ll ans = 0;
  ll tdam = 0;
  for(int i=0; i<n; ++i){
    int xf = x[i].first, xs = x[i].second;
    
    while(!que.empty()){
      if(que.front().first < xf){
        tdam -= que.front().second;
        que.pop();
      }else break;
    }
    if((ll)xs <= tdam) continue;
    else xs -= (int)tdam;
    
    int sdam = ((xs -1) /a +1) *a;
    ans += (xs -1) /a +1;
    tdam += sdam;
    if((ll)xf + 2*d < INF) que.push(make_pair(xf + 2*d, sdam));
  }
  cout << ans << endl;
}
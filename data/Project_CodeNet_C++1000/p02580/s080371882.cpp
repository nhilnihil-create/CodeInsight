#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int h,w,m;
  cin >> h >> w >> m;
  vector<pair<int,int>> p(m);
  for(int i=0;i<m;i++) cin >> p[i].first >> p[i].second;

  vector<int> bh(h+1),bw(w+1);
  for(int i=0;i<h+1;i++) bh[i] = 0;
  for(int i=0;i<w+1;i++) bw[i] = 0;

  for(int i=0;i<m;i++){
    bh[p[i].first]++;
    bw[p[i].second]++;
  }

  int max_bh = 0;
  int max_bw = 0;
  for(int i=0;i<h+1;i++) max_bh = max(max_bh,bh[i]);
  for(int i=0;i<w+1;i++) max_bw = max(max_bw,bw[i]);

  ll mbh_cnt = 0;
  ll mbw_cnt = 0;
  for(int i=0;i<h+1;i++) mbh_cnt += (bh[i] == max_bh);
  for(int i=0;i<w+1;i++) mbw_cnt += (bw[i] == max_bw);

  bool f = false;
  ll cnt = 0;
  for(int i=0;i<m;i++){
    if(bh[p[i].first] == max_bh && bw[p[i].second] == max_bw){
      cnt++;
    }
  }

  ll ans = max_bh + max_bw;
  if(cnt == mbh_cnt * mbw_cnt) cout << ans - 1 << endl;
  else cout << ans << endl;
}
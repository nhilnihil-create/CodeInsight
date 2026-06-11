#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
#define P pair<ll, ll>

set<pair<int, int>> bomb;

int main(){
  ll H,W,M;cin>>H>>W>>M;
  map<int, int> row,col;
  ll maxr=0,maxc=0;
  rep(i,M){
    ll h,w;cin>>h>>w;h--,w--;
    row[h]++;col[w]++;
    if(row[h]>maxr) maxr=row[h];
    if(col[w]>maxc) maxc=col[w];
    bomb.insert({h,w});
  }
  vll vr{},vc{};
  for(auto r : row){
    if(r.second==maxr) vr.push_back(r.first);
  }
  for(auto c : col){
    if(c.second==maxc) vc.push_back(c.first);
  }
  ll ans = maxr + maxc;
  for(auto r : vr) {
    for(auto c : vc){
      if(bomb.find({r,c})!=bomb.end()) continue;
      cout << ans << endl;
      return 0;
    }
  }
  --ans;
  cout << ans << endl;
}
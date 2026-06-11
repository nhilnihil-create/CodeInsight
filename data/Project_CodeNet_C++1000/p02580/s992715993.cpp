#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int H,W,M; cin >> H >> W >> M;
  vi cnth(H),cntw(W),h(M),w(M);
  set<pair<int,int>> s;
  rep(i,M){
    cin >> h[i] >> w[i];
    h[i]--;  w[i]--;
    cnth[h[i]]++;
    cntw[w[i]]++;
    s.insert({h[i],w[i]});
  }
  int mxy = 0, mxx = 0;
  rep(i,H) chmax(mxy,cnth[i]);
  rep(i,W) chmax(mxx,cntw[i]);
  vi y,x;
  rep(i,H) if(mxy == cnth[i]) y.push_back(i);
  rep(i,W) if(mxx == cntw[i]) x.push_back(i);
  int ans = mxy+mxx;
  for(auto a : y) for(auto b : x){
    if(s.count({a,b})) continue;
    cout << ans;
    return 0;
  }
  cout << ans-1;
  cout << "\n";
  return 0;
}

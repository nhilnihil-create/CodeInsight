#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

int main(){
  ll h,w,m;
  cin >> h >> w >> m;
  set<pair<ll,ll>> st;
  vector<pair<ll,ll>> vec1(h),vec2(w);
  rep(i,h){
    vec1[i].first = 0;
    vec1[i].second = i;
  }
  rep(i,w){
    vec2[i].first = 0;
    vec2[i].second = i;
  }
  rep(i,m){
    cin >> t1 >> t2;
    t1--,t2--;
    vec1[t1].first++;
    vec2[t2].first++;
    st.insert({t1,t2});
  }
  sort(all(vec1),greater<pair<ll,ll>>());
  sort(all(vec2),greater<pair<ll,ll>>());
  ll ans = vec1[0].first + vec2[0].first;
  ll piv1 = vec1[0].first;
  ll piv2 = vec2[0].first;
  bool can = false;;
  rep(i,h){
    if(can){
      break;
    }
    rep(j,w){
      if(vec1[i].first == piv1 && vec2[j].first == piv2){
        if(st.find({vec1[i].second,vec2[j].second}) == st.end()){
          //cout << i << " " << j << endl;
          can = true;
          break;
        }
      }else{
        break;
      }
    }
  }
  if(!can){
    ans--;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) a[i]--;
  vector<int> idx(n);
  rep(i,n) idx[a[i]]=i;
  
  set<int>st;
  ll ans = 0;
  for(int p=n-1;p>=0;p--){
    int i = idx[p];
    ll c = 0;
    {
      //calc c;
      st.insert(i);
      vector<int> l(2,-1);
      vector<int> r(2,n);
      {
        // calc l
        auto it = st.find(i);
        rep(j,2){
          if(it == st.begin())break;
          --it;
          l[j] = *it;
        }
      }
      {
        // calc r
        auto it = st.find(i);
        rep(j,2){
          ++it;
          if(it == st.end())break;
          r[j] = *it;
        }
      }
      vector<int> ls(2);
      vector<int> rs(2);
      ls[0] = i-l[0];
      ls[1] = l[0]-l[1];
      rs[0] = r[0]-i;
      rs[1] = r[1]-r[0];
      c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
    }
    ans += c*(p+1);
  }
  cout << ans << endl;
  return 0;
}
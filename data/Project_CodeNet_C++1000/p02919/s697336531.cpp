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
  vector<int> idx(n+1);
  rep(i,n) idx[a[i]]=i+1;
  
  multiset<int>st;
  st.insert(0);
  st.insert(0);
  st.insert(n+1);
  st.insert(n+1);
  //番兵
  
  ll ans = 0;
  for(int p=n;p>=1;p--){
    auto it = st.lower_bound(idx[p]);
    ll r1 = *it;
    
    it++;
    ll r2 = *it;
    
    it--;
    it--;
    ll l1 = *it;
    
    it--;
    ll l2 = *it;
    
    ll c = (r1-idx[p])*(l1-l2) + (r2-r1)*(idx[p]-l1);
    ans += c*p;
    
    st.insert(idx[p]);
  }
  cout << ans << endl;
  return 0;
}
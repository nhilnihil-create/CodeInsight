#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> mp;
  rep(i,n) mp[a[i]]=i;
  set<int> st={-1,n};
  ll ans=0;
  for(ll i=n;i>=1;i--){
    auto itr=st.upper_bound(mp[i]);
    int r=*itr;
    int r2=r==n?r+1:*(next(itr));
    int l=*(prev(itr));
    int l2=l==-1?l-1:*(prev(itr,2));
    int dr=l==-1?0:r-mp[i];
    int dl=r==n?0:mp[i]-l;
    int dr2=r2-r;
    int dl2=l-l2;
    ans+=i*(dl2*dr+dr2*dl);
    st.insert(mp[i]);
  }
  cout << ans << endl;
}
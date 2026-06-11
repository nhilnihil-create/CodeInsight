#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){ cin >> a[i]; a[i]--; }
  vector<int> idx(n);
  rep(i,n){ idx[a[i]] = i; }

  set<int> st;
  ll ans = 0;
  for(int x=n-1; x>=0; x--){
    int i = idx[x];
    ll c = 0;
    st.insert(i);
    vector<int> l(2,-1);
    vector<int> r(2,n);
    auto it = st.find(i);
    rep(j,2){
      if(it==st.begin())break;
      it--;
      l[j] = *it;
    }
    it = st.find(i);
    rep(j,2){
      it++;
      if(it==st.end())break;
      r[j] = *it;
    }
    vector<int> ls(2); ls[0] = i-l[0]; ls[1] = l[0]-l[1];
    vector<int> rs(2); rs[0] = r[0]-i; rs[1] = r[1]-r[0];
    c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
    ans += c*(x+1);
  }

  cout << ans << endl;
  return 0;
}

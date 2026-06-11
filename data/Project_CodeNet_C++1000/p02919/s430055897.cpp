#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N;
  cin>>N;
  vector<ll> P(N);
  ll point[N+1];
  for(ll i=0;i<N;++i) {
    cin>>P[i];
    point[P[i]] = i;
  }
  set<ll> st;
  st.insert(-1);
  st.insert(N);
  ll ans = 0;
  auto l1=st.begin(), l2=st.begin(), r1=st.end(), r2=st.end(), index=st.end();
  for(ll i=N;i>=1;--i) {
    st.insert(point[i]);
    index = st.find(point[i]);
    r1 = next(index);
    l1 = prev(index);
    if(*r1==N) {
      if(*l1==-1) {
        continue;
      }
      else {
        l2 = prev(l1);
        ans += i*(*r1-*index)*(*l1-*l2);
      }
    }
    else {
      r2 = next(r1);
      if(*l1==-1) {
        ans += i*(*index-*l1)*(*r2-*r1);
      }
      else {
        l2 = prev(l1);
        ans += i*(*index-*l1)*(*r2-*r1)+i*(*l1-*l2)*(*r1-*index);
      }
    }
  }
  cout<<ans<<endl;
}

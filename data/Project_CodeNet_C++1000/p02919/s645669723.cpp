#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0;cin>>n;
  lvector p(n,0),q(n+1,0);
  rep(i,n) cin>>p[i],q[p[i]]=i;
  multiset<ll> st{-1,-1,n,n};
  for(ll i=n;i>=0;--i) {
    ll pos=q[i];
    ll r1=*st.lower_bound(pos);
    ll r2=*next(st.lower_bound(pos));
    ll l1=*prev(st.lower_bound(pos));
    ll l2=*prev(st.lower_bound(pos),2);
    ans+=((r2-r1)*(pos-l1)+(l1-l2)*(r1-pos))*i;
    st.insert(pos);
  }
  print(ans);
  return 0;
}
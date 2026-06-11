#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cassert>

#include<cmath>
#include<functional>
#include<algorithm>

#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<tuple>

#define TEST {IS_TEST=true;}
#define fi first
#define se second
#define pb(x) {push_back(x);}

using namespace std;
using ll = int_fast64_t;
using v_b = vector <bool>;
using v_ll = vector <ll>;
using str = string;
using v_str = vector <string>;
using p_ll = pair < ll,ll >;
using vv_b = vector < v_b >;
using vv_ll = vector < v_ll >;
using vp_ll = vector < p_ll >;
using vvv_ll = vector < vv_ll >;
using vvp_ll = vector < vp_ll >;

using ld = long double;
using v_ld = vector <ld>;
using vv_ld = vector<v_ld>;

bool IS_TEST=false;
ll ll_min64=1LL<<63;
ll ll_max64=~ll_min64;
ll ll_min32=1LL<<31;
ll ll_max32=~ll_min32;

ll MOD = 1000000007;

/*displaying functions for debug*/
template<class T> void show2(const T &x){cout << x;}
template<class T1,class T2> void show2(const pair<T1,T2> &x){
  cout << "{" << show2(x.first) << "," << show2(x.second) << "}";
}
template<class T> void show(const T &x){
  if (!IS_TEST) return;
  show2(x); cout <<endl;
}
template<class T> void v_show(const T &v, ll n=-1){
  if (!IS_TEST) return;
  auto itr=v.begin(); ll m=n;
  while(itr!=v.end() && m!=0 ){ show2(*itr); cout << " "; itr++; m--;}
  cout << endl;
}
template<class T> void vv_show(const T &v, ll n=-1){
  if (!IS_TEST) return;
  cout << "--------------------------------\n";
  auto itr=v.begin(); ll m=n;
  while(itr!=v.end() && m!=0 ){ v_show(*itr,n); itr++; m--;}
  cout << "--------------------------------" << endl;
}
/*--------------------------------*/

/*loading integers*/
void load(ll& x1){ cin >> x1; }
void load(ll& x1,ll& x2){ cin >> x1 >> x2; }
void load(ll& x1,ll& x2,ll& x3){ cin >> x1 >> x2 >> x3; }
void load(ll& x1,ll& x2,ll& x3,ll& x4){ cin >> x1 >> x2 >> x3 >> x4; }
void v_load(ll n, v_ll& v1, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init);
    for (ll i=0;i<n;i++){ cin >> v1[i+head]; }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init);
    for (ll i=0;i<n;i++){ cin >> v1[i+head] >> v2[i+head]; }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, v_ll& v3, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init); v3.assign(m,init);
    for (ll i=0;i<n;i++){ cin >> v1[i+head] >> v2[i+head] >> v3[i+head]; }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, v_ll& v3, v_ll& v4, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init); v3.assign(m,init); v4.assign(m,init);
    for (ll i=0;i<n;i++){ cin >> v1[i+head] >> v2[i+head] >> v3[i+head] >> v4[i+head]; }
}
/*--------------------------------*/

v_ll local_sort(ll x1=ll_max64, ll x2=ll_max64, ll x3=ll_max64, ll x4=ll_max64){
    v_ll x{x1,x2,x3,x4};
    sort(x.begin(),x.end());
    return x;
}

ll max(ll x,ll y){return x>y?x:y;}
ll max(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=max(ans,*b);b++;}
    return ans;
}
ll argmax(v_ll::iterator b,v_ll::iterator e){
    ll ans=0, cnt=0, val=*b;
    while (b<e) { if (val<*b) {ans=cnt; val=*b;} cnt++; b++;}
    return ans;
}

ll min(ll x,ll y){return x>y?x:y;}
ll min(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=min(ans,*b);b++;}
    return ans;
}
ll argmin(v_ll::iterator b,v_ll::iterator e){
    ll ans=0, cnt=0, val=*b;
    while (b<e) { if (val>*b) {ans=cnt; val=*b;} cnt++; b++;}
    return ans;
}

ll sum(v_ll::iterator b,v_ll::iterator e){
    ll ans=0;
    while (b<e) {ans+=*b;b++;}
    return ans;
}

template<class T> void chmax(T& x,const T& y){ if (x>=y) return; x=y; }
template<class T> void chmin(T& x,const T& y){ if (x<=y) return; x=y; }
template<class T,class S> void chmax(T& x,S& xx,const T& y,const S& yy){
  if (x>=y) return; x=y; xx=yy;
}
template<class T,class S> void chmin(T& x,S& xx,const T& y,const S& yy){
  if (x<=y) return; x=y; xx=yy;
}

template<class T> void quit(T x){cout << x << endl; exit(0);}

ll rem(ll x,ll y){ ll z=x%y; return z>=0?z:z+y; }

//setprecision(digit)

ll N,M,K,H,W,ans;
v_ll P,Q;
int main(){
    load(N);
    v_load(N,P);
    for (ll i=0;i<N;i++) P[i]--;
    Q.assign(P.size(),0);
    for (ll i=0;i<N;i++) Q[P[i]]=i;
    multiset<ll> S;
    S.insert(N);
    S.insert(N);
    S.insert(-1);
    S.insert(-1);
    ans=0;
  //TEST;
    //v_show(Q);
    for (ll i=N-1;i>=0;i--){
      S.insert(Q[i]);
      auto itr = S.find(Q[i]);
      ll a0,a1,a2,a3,a4;
      itr--;itr--;
      a0=*itr;itr++;
      a1=*itr;itr++;
      a2=*itr;itr++;
      a3=*itr;itr++;
      a4=*itr;
      //printf("%lld %lld %lld %lld %lld %lld\n",i,a0,a1,a2,a3,a4);
      ans+=(i+1)*(a3-a2)*(a1-a0);
      ans+=(i+1)*(a4-a3)*(a2-a1);
    }
    cout << ans << endl;
}



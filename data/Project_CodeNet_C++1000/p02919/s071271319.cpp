#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
using ll = long long int;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define fs first
#define sd second

template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;


void solve(){
  int n; cin >> n;
  int INF = 1<<25;
  V<int> p(n+5,INF), pl(n+5), pll(n+5,0), plr(n+5,0), prl(n+5,n+1), prr(n+5,n+1); 
  FOR(i,0,n) {
    cin >> p[i+1];
    pl[p[i+1]] = i+1;
  }/*
  FOR(i,1,n){
    int u = pl[i], cnt = 0;
    IFOR(j,1,u){
      if(p[j]>i){
        if(cnt==0) plr[i] = j;
        if(cnt==1) pll[i] = j;
        cnt++;
      }
      if(cnt==2) break;
    }
    //if(plr[i]==pll[i]) pll[i] = -1;
    cnt = 0;
    FOR(j,u,n+2){
      if(p[j]>i){
        if(cnt==0) prl[i] = j;
        if(cnt==1) prr[i] = j;
        cnt++;
      }
      if(cnt==2) break;
    }
    //if(prr[i]==prl[i]) prr[i] = n+2;
  }*/
  set<int> S, T;
  S.insert(n+1); T.insert(-n-1); S.insert(n+2); T.insert(-n-2);
  S.insert(0); T.insert(0); S.insert(-1); T.insert(1);
  IFOR(i,1,n+1){
    int ip = pl[i];
    auto aa = S.upper_bound(ip);
    auto ab = S.upper_bound(*aa);
    if(aa!=S.end()  &&  (*aa)>=0 && (*aa) <= n+1) prl[i] = *aa;
    if(aa!=S.end() && ab != T.end() && (*ab)>=0 && (*ab) <= n+1) prr[i] = *ab;
    aa = T.upper_bound(-ip);
    ab = T.upper_bound(*aa);
    if(aa!=S.end()  &&  -(*aa)>=0 && -(*aa) <= n+1) plr[i] = -(*aa);
    if(aa!=S.end() && ab != T.end() &&-(*ab)>=0 && -(*ab) <= n+1) pll[i] = -(*ab);
    S.insert(ip);
    T.insert(-ip);
  }
  ll ans = 0;
  FOR(i,1,n){
    ll ip = pl[i];
    ll tmp = ((ll)(ip - plr[i])*(ll)(prr[i]-prl[i]) + (ll)(prl[i]-ip) *(ll)(plr[i]-pll[i]));
    ans += tmp*i;
    //cout << i << "~" << tmp << '\n';
  }
  /*
  FOR(i,0,n+2){
    cout << pll[i] << '~' << plr[i] << "~~" << prl[i] << '~' << prr[i] << '\n';
  }*/
  cout << ans << '\n';
}

int main(){
  solve();
  return 0;
}
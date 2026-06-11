#include<bits/stdc++.h>

#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed fixed<<setprecision(14)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
const lol Mod=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k,r,q;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n;
  vector<int> x(n);
  vector<int> l(n);
  for(int i=0;i<n;i++){
    cin >>x[i]>>l[i];
  }
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++){
    p[i]=mp(x[i]+l[i]-1,x[i]-l[i]);
  }
  sort(p.begin(),p.end());
  lol place=p[0].fi;
  lol ans=1;
  for(int i=1;i<n;i++){
    if(p[i].se>place){
      ans++;
      place=p[i].fi;
    }
  }
  cout <<ans<<'\n';
  return (0);
}

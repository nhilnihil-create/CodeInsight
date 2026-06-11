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
template <class A, class B> inline A max(A a, B b){return(a>b?a:b);}
template <class A, class B> inline A min(A a, B b){return(a<b?a:b);}
const lol inf=(1LL<<60);
const lol MOD=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k,r;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol ans=0;
  int a,b,c;
  cin >>a>>b>>c>>k;
  ans+=min(k,a);
  k-=min(k,a);
  k-=min(k,b);
  ans-=min(k,c);
  cout <<ans<<'\n';
  return (0);
}
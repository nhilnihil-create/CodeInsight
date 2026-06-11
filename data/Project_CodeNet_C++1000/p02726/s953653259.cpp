#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const lol MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y;
  cin >>n>>x>>y;
  vector<int> ans(n+3,0);
  for(int i=1;i<n;i++){
    for(int j=i+1;j<=n;j++){
      int tmp=min(abs(i-x)+abs(y-j),abs(i-y)+abs(x-j));
      ans[min(j-i,tmp+1)]++;
    }
  }
  for(int i=1;i<n;i++) cout <<ans[i]<<'\n';
  return (0);
}
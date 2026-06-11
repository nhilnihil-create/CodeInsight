#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const lol MOD=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n>>k;
  vector<int> a(n);
  vector<int> ans(n);
  for(auto&&o:a) cin >>o;
  lol sum=0;
  lol so=0;
  set<int> se;
  se.insert(0);
  ans[0]=0;
  while(1){
    if(k<=0) break;
    sum=a[sum]-1;
    so++;
    k--;
    if(se.find(sum)!=se.end()){
      k%=so-ans[sum];
      break;
    }
    ans[sum]=so;
    se.insert(sum);
  }
  for(int i=0;i<k;i++){
    sum=a[sum]-1;
  }
  cout <<sum+1<<'\n';
  return (0);
}
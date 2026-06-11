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
const int MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,k;
  cin >>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >>a[i];
  int low=0,high=MOD;
  while(high-low>1){
    int mid=(high+low)/2;
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=(a[i]-1)/mid;
    }
    if(sum<=k) high=mid;
    else low=mid;
  }
  cout <<high<<'\n';
  return (0);
}
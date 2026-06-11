#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  itn n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b(n);
  rep(i,n) cin >> b[i];
  priority_queue<pii> q;
  rep(i,n){
    if(b[i]>a[i]) q.push(pii(b[i],i));
    if(b[i]<a[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans=0;
  while(a!=b){
    int x,itr;
    tie(x,itr)=q.top();
    q.pop();
    int y=b[(itr+n-1)%n]+b[(itr+1)%n];
    if(x-a[itr]>=y){
      ans+=(x-a[itr])/y;
      x-=(x-a[itr])/y*y;
      b[itr]=x;
      if(x!=a[itr]) q.push(pii(x,itr));
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
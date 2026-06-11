#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define all(c) begin(c),end(c)
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
 
 
 
 
int main() {
  int n;
  cin>>n;
  int n2=1<<n;  //=pow(2,n)と同義
  vi a(n2),s;
  rep(i,n2)cin>>a[i];
  sort(all(a));
  s.push_back(a.back());//aの最大をsに入れる
  a.back()=-1;
  rep(i,n){
    vi p=s;
    sort(all(p));
    int ai=n2-1;
    while(p.size()>0&&ai>=0){
      if(a[ai]==-1){
        --ai;
        continue;
      }
      if(a[ai]<p.back()){
        s.push_back(a[ai]);
        p.pop_back();
        a[ai]=-1;
      }
      --ai;
    }
      if(p.size()>0){
      puts("No");
      return 0;
      }

  }

  puts("Yes");



}



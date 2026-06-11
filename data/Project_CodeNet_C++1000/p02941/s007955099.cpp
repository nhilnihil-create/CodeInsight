#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N=200005;
int a[N],b[N];
set<ii> s;
void rekt()
{
  cout<<-1<<endl;
  exit(0);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n;
  cin>>n;
  int cnt=0;
  rep(i,1,n+1) cin>>a[i];
  rep(i,1,n+1)
    {
      cin>>b[i];
      if(a[i]==b[i]) cnt++;
      else s.insert(mp(b[i],i));
    }
  b[n+1]=b[1];
  b[0]=b[n];
  ll ans=0;
  while(cnt!=n)
    {
      auto it=*s.rbegin();
      s.erase(it);
      int id=it.se;
      if(b[id]==a[id]) rekt();
      int sum=b[id-1]+b[id+1];
      int num=(b[id]-a[id])/sum;
      num=min(num,(b[id]-1)/sum);
      if(!num) rekt();
      ans+=num;
      b[id]-=num*sum;
      if(b[id]==a[id]) cnt++;
      else s.insert(mp(b[id],id));
      if(id==n) b[0]-=num*sum;
      if(id==1) b[n+1]-=num*sum;
    }
  cout<<ans<<endl;
  return 0 ;
}

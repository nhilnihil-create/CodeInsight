#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
int a[510];
vector<int> yaku(int n){
  vector<int> res;
  for(int i=1;i*i<=n;i++){
    if((n%i)!=0)continue;
    res.pb(i);
    if((i*i)!=n)res.pb(n/i);
  }
  sort(all(res));
  return res;
}
signed main(){
  int n,k;cin>>n>>k;
  int sum=0;
  int ans=1;
  rep(i,n)cin>>a[i],sum+=a[i];
  for(int d:yaku(sum)){
    vector<int> v;
    int wa=0;
    int sa=0;
    rep(i,n){
      v.pb(a[i]-(a[i]/d)*d);
      wa+=(a[i]-(a[i]/d)*d);
    }
    wa/=d;
    sort(all(v));
    rep(i,n){
      if(i>=n-wa)sa+=d-v[i];
      else sa+=v[i];
    }
    if(sa/2<=k)ans=max(ans,d);
  }
  cout<<ans<<endl;
  return 0;
}
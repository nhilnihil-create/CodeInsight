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

int a[100010];
int neg;
int ans=0;
vector<P> res;
signed main(){
  int n;cin>>n;
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  
  if(a[0]>0){
    for(int i=1;i<=n-2;i++){
      res.pb(P(a[0],a[i]));
      a[0]-=a[i];
    }
    res.pb(P(a[n-1],a[0]));
    ans=a[n-1]-a[0];
  }
  
  else if(a[n-1]<0){
    for(int i=n-2;i>=0;i--){
      res.pb(P(a[n-1],a[i]));
      a[n-1]-=a[i];
    }
    ans=a[n-1];
  }
  
  else{
    int ima=n-2;
    while(a[ima]>0){
      res.pb(P(a[0],a[ima]));
      a[0]-=a[ima];
      ima--;
    }
    rep(i,ima+1){
      res.pb(P(a[n-1],a[i]));
      a[n-1]-=a[i];
    }
    ans=a[n-1];
  }
  cout<<ans<<endl;
  rep(i,n-1){
    cout<<res[i].F<<" "<<res[i].S<<endl;
  }
  return 0;
}
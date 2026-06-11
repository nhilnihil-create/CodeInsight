#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n,m;
  cin>>n>>m;
  int a[m],b[m];
  int c[m][n];
  rep(i,m){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
      cin>>c[i][j];
    }
  }
  
  vector<ll> dp(5000,INF);
  dp[0]=0;
  rep(i,m){
    int now=0;
    rep(j,b[i]){
      now |= 1<<(c[i][j]-1);
    }
    
    for(int bit=0;bit<(1<<n);bit++){
      dp[bit | now]=min(dp[bit|now],dp[bit]+a[i]);
    }
  }
  
  if(dp[(1 << n) - 1] == INF) dp[(1 << n) - 1] = -1;
  cout << dp[(1 << n) - 1] << endl;
  
}
  
  
  
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;
int a[400006];
signed main(){
  int k,n;cin>>k>>n;
  rep(i,n)cin>>a[i];
  rep(i,n)a[i+n]=a[i]+k;
  int ans=inf;
  rep(i,n)ans=min(ans,a[i+n-1]-a[i]);
  cout<<ans<<endl;
}
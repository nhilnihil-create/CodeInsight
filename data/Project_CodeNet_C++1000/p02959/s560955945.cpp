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
int b[100010];
signed main(){
  int n;cin>>n;
  rep(i,n+1)cin>>a[i];
  rep(i,n)cin>>b[i];
  int ans=0;
  rep(i,n){
    if(b[i]<=a[i])a[i]-=b[i],ans+=b[i];
    else if(b[i]<=a[i]+a[i+1])a[i+1]-=(b[i]-a[i]),a[i]=0,ans+=b[i];
    else ans+=a[i]+a[i+1],a[i]=0,a[i+1]=0;
  }
  cout<<ans<<endl;
  return 0;
}
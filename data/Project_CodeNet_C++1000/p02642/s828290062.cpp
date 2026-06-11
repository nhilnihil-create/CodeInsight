#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N];
int vis[N],can[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],vis[a[i]]++;
  for(int i=1;i<=1000000;i++)if(vis[i]){
    for(int j=vis[i]==1?2*i:i;j<=1000000;j+=i){
      can[j]=1;
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=can[a[i]]^1;
  }
  cout<<ans<<'\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> PPI;
typedef pair<LL, LL> PL;
typedef long long LL;
// LLONG_MIN, INT_MIN
#define xx first
#define yy second

// int seg[810000];
// void build(int id=1, int l=0, int r = n){
//   if(l==r-1){
//     seg[id] = da[l];
//   }
//   int mid = (l+r)/2;
//   build(id*2, l, mid);
//   build(id*2+1,mid, r);
//   s[id] = max(s[id*2],s[id*2+1]);
// }
// void mx(int x, int y, int id=1, int l=0, int r = n){
//   if(x>=r||y<=l) return -1;
//   if(l>=x&&r<=y)return seg[id];
//   int mid = (l+r)/2;
//   return max(mx(x,y,id*2,l,mid),mx(x,y,id*2+1,mid, r));
// }

const int MOD = 1e9 + 7;
LL dp[2100][2100];
int main()
{
  //freopen("input", "r", stdin);
  // freopen("output", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  LL n,m;
  cin>>n>>m;
  LL a[2100], b[2100];
  for(LL i=0;i<n;i++)
    cin>>a[i];
  for(LL i=0;i<m;i++)
    cin>>b[i];

  memset(dp, 0, sizeof(dp));
  // for(LL i=0;i<=n;i++)
  //   for(LL j=0;j<=n;j++)
  //     if(i==0||j==0)
  //       dp[i][j] = 1;
  for(LL i=1;i<=n;i++)
    for(LL j=1;j<=m;j++){
      if(a[i-1]==b[j-1]){dp[i][j] += dp[i-1][j-1]+1;}
      dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
      // cout<<dp[i][j]<<endl;
      dp[i][j]%=LL(1e9+7);

    }
    // for(LL i=1;i<=n;i++)
    //   {for(LL j=1;j<=n;j++)
    //     cout<<dp[i][j]<<" ";
    //   cout<<endl;
    //   }
  cout<<(dp[n][m]+1+MOD)%LL(1e9+7)<<endl;

}

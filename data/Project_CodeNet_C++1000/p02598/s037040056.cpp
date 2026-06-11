#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define _h cout<<"here"<<endl;
#define fill(a,v) memset(a,v,sizeof(a));
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i+=1)
#define prd(a,n) rep(i,n) cout<<a[i]<<" \n"[i==n-1];// printf("%s\n"," " );
#define ff first
#define ss second
#define pu push_back
const int inf = 1e9+10;
const ll INF = 2e18+10;
const int Mod = 1e9+7;
const int MAXN = 1000010;
const int N=2e5+10;
const int M=210;
const int M1=1e9+7;
const int M2=1e9+9;
const int base=131;
int a[N];
int main()
{
  ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n,k,ans=inf;
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  // sort(a+1,a+n+1);
  int l=1,r=1e9+10;
  while(l<=r)
  {
    int m=(l+r)>>1,cnt=0;
    // cout<<m<<endl;
    for(int i=1;i<=n;i++)
    {
      int x=(a[i]/m)+((a[i]%m)!=0);
      x=max(x-1,0);
      // cout<<cnt<<" ";
      cnt+=x;
    }
    // break;
    // cout<<endl;
    if(cnt<=k)
    {
      ans=min(ans,m);
      // cout<<ans<<" "<<cnt<<endl;
      r=m-1;
    }
    else
    {
      l=m+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}

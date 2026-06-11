#include<bits/stdc++.h>
#define For(i,m,n) for(int i=m;i<n;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ull unsigned long long
#define lli long long int
#define pb push_back
#define all(x) x.begin(),x.end()
ll mob=1000000007;
using namespace std;
int main()
{ 
int n,p;
cin>>n>>p;
string h;
cin>>h;
int u=h.length();
int dp[u+1];
dp[u]=0;
int ten =1;
 if (10%p == 0) { // 2,5
    ll ans = 0;
    FOR(r,u) {
      if ((h[r]-'0') % p == 0) {
        ans += r+1;
      }
    }
    cout << ans << endl;
    return 0;
  }
for(int i=u-1;i>=0;i--)
{
  int a=(h[i]-'0')*ten%p;
  dp[i]=(dp[i+1]+a)%p;
  ten*=10;ten=ten%p;
}
vector<int> cnt(p,0);
ll ans =0;
for(int i=u;i>=0;i--)
{
  ans+=cnt[dp[i]];
  cnt[dp[i]]++;
}
cout<<ans;




return 0;
}










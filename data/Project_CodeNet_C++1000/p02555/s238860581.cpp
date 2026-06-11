//https://atcoder.jp/contests/abc178/tasks/abc178_d

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;
#define all(v) v.begin(),v.end()
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,szeof(a))
#define pp pair<ll,ll>
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
#define el cout<<'\n';
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll dp[2001];

ll find(ll n){

    if(n==0)
    return 1;

    if(n<0)
    return 0;

    if(dp[n]!=-1)
        return dp[n];
    ll ans=0;
    for(int i=3;i<=n;i++){
        ans+=find(n-i);
        ans=ans%mod;
    }
    dp[n]=ans;
    return ans;
}
void solve(){
 ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    
    cout<<find(n);
}
int main()
{
    ll t=1;
   // cin>>t;
    while(t--)
    {
     solve();
     cout<<endl;
    }
	return 0;
}
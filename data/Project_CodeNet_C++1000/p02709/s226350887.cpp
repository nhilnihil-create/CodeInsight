//  RAKSHIT KADAM
 #include <bits/stdc++.h>
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree< int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update>
 #warning !!!check the size of arrayss!!!
 #define ll long long
 #define int long long
 #define MOD  1000000007
 #define newMOD  998244353
 #define MAX 300006
 #define P(gg) for(auto rax:gg){cout<<rax<<" ";}cout<<endl;
 #define Need_for_speed(activated) ios_base :: sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
 #define satisfy ll t; cin>> t; while(t--)
 #define inp(n) int n;cin >> n
 #define mp make_pair
 #define pb push_back
 #define endl "\n"
 #define x first
 #define y second
 #define fore(i,a,b) for(ll i=a;i<b;i++)
 #define forci(i,n) for(ll i=0;i<n;i++)
 #define INF 2000000000000000005

 #define vi vector<ll>
#define pi 3.1415926535897932384626433832795
#define Endl endl
#define lb lower_bound
#define ub upper_bound

using namespace std;
//ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
//int power(int x, unsigned int y, unsigned int m){ if (y == 0) return 1;int p = power(x, y/2, m) % m;  p = (p * p) % m;                                                  return (y%2 == 0)? p : (x * p) % m;}
 //ddfdsfdfs

//ll modInverse(int a, int m){ return power(a, m-2, m);} // if a and m are relativelyprime

vector< pair<ll,ll> >a ;

void solve()
{
    ll n;cin>>n;
    ll x;
    forci(i,n){cin>>x;a.pb(mp(x,i));}
    ll dp[n+3][n+4];memset(dp,0,sizeof dp);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(ll i=0;i<n;i++)
    {
        for(ll j=0,k=i;k>=0;j++,k--)
        {
            dp[j+1][k]=max(dp[j+1][k],dp[j][k]+a[i].x*abs(j-a[i].y));
            dp[j][k+1]=max(dp[j][k+1],dp[j][k]+a[i].x*abs(n-1-k-a[i].y));
        }
    }
    ll ans=0;
    for(ll i=0,j=n;j>=0;j--,i++)
    {
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}
signed main()
{
 
   
    Need_for_speed(activated);
//satisfy
//    {
//   solve();
//    }


 solve();
    return 0;
}

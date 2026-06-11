//  RAKSHIT KADAM
//ALWAYS USE &IT FOR ITERATING USING AUTO ...
//USE COUNT(STARTING ADDRESS, ENDING ADRESS ,VALUE) FOR FINDING THE COUNT IN THE RESPECTIVE DATA STRUCTURE
//NOTE THAT MEMSET CANNOT ASSIGN A VALUE OF 10^18 IT WILL ASSIGN A LOWER VALUE THAN THAT!!!
 #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree< int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#warning !!!check the size of arrayss!!!

// NUMERIC DEFINITIONS :
    #define INF 2000000000000000005
    #define MOD  1000000007
    #define newMOD  998244353
    #define MAX 300006
    #define pi 3.1415926535897932384626433832795

 #define ll long long
 #define int long long
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
 #define vi vector<ll>
 #define Endl endl
 #define lb lower_bound
 #define ub upper_bound
#define pii pair<ll,ll>
#define MAXN 402
 #define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)
 #define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
int power(int x, unsigned int y, unsigned int m){ if (y == 0) return 1;int p = power(x, y/2, m) % m;  p = (p * p) % m;                                                  return (y%2 == 0)? p : (x * p) % m;}
ll modInverse(int a, int m){int g = gcd(a, m); { return power(a, m-2, m);}}



ll n,m;
string s[103];
ll dp[103][104];
 
void solve()
{
    cin>>n>>m;
    string d;
    
    for(ll i=1;i<=n;i++)cin>>d,s[i]='@'+d;
    dp[1][1] = s[1][1]=='#';
    for(ll i=2;i<=n;i++)for(ll j=2;j<=m;j++)dp[i][j] = INF;
    for(ll i=2;i<=n;i++)
    {
        if(s[i][1]=='.')dp[i][1]=dp[i-1][1];
        else
        {
            if(s[i-1][1]=='.')dp[i][1]++;
            dp[i][1]+=dp[i-1][1];
        }
        
    }
    for(ll j=2;j<=m;j++)
    {
        if(s[1][j]=='.')dp[1][j]+=dp[1][j-1];
        else
        {
            if(s[1][j-1]=='.')dp[1][j]++;
            dp[1][j]+=dp[1][j-1];
        }
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=2;j<=m;j++)
        {
            if(s[i][j]=='.')dp[i][j] =min(dp[i][j-1],dp[i-1][j]);
            else
            {
                if(s[i-1][j]=='.')dp[i][j] =min(dp[i][j],dp[i-1][j]+1);
                
                else {dp[i][j]=min(dp[i][j],dp[i-1][j]);}
                
                if(s[i][j-1] == '.' )dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                else dp[i][j] =min(dp[i][j],dp[i][j-1]);

            }
        }
    }
   
    
    
    cout<<dp[n][m]<<endl;
}
signed main()
{
 
    Need_for_speed(activated);
//satisfy
//    {
//   solve();
//   }

    solve();
    return 0;
}

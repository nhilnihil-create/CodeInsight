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
 #define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)
 #define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
//int power(int x, unsigned int y, unsigned int m){ if (y == 0) return 1;int p = power(x, y/2, m) % m;  p = (p * p) % m;                                                  return (y%2 == 0)? p : (x * p) % m;}
//ll modInverse(int a, int m){int g = gcd(a, m); { return power(a, m-2, m);}}

void solve()
{
    string s;cin>>s;
    ll n = s.length();
    ll dp[n+2][14];memset(dp,0,sizeof dp);
    ll ten = 10 ;
    
    if(s[n-1]=='?')
    {
         for(ll i=0;i<=9;i++)dp[n-1][i]=1;
        
    }
    else
    {
        
       dp[n-1][s[n-1]-'0']=1;
    }
    for(ll i=n-2;i>=0;i--)
    {
        if(s[i]!='?')
        {
            ll num = s[i]-'0';
            num = (num*ten)%13;
            
            for(ll j=0;j<=12;j++)
            {
                (dp[i][(num+j)%13] += dp[i+1][j])%=MOD;
                
            }
        }
        else
        {
            for(ll k=0;k<=9;k++)
            {
               
                ll num = k;
                num = (num*ten)%13;
                for(ll j=0;j<13;j++)
                {
                    (dp[i][(num+j)%13] += dp[i+1][j])%=MOD;
                }
            }
        }
        ten*=10;
        ten%=13;
    }
    cout<<(dp[0][5])%MOD<<endl;
 
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

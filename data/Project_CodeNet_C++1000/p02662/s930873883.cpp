#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 998244353
#define inf 1e18+42
#define endl "\n"
#define pi 3.1415926535897932384626433832795028841971693993751058
#define maxn 100005

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
#define ceil(a,b) (a+b-1)/b
 
using namespace std;

int binpow(int a, int b , int p ) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

int modinv( int a , int p )
{
    return (binpow(a,p-2,p)%p);
}
//START OF CODE ->->->->->->->

void solve()
{
    int n,s;
    cin>>n>>s;

    vector<int> a(n);

    rep(i,0,a.size())
    {
        cin>>a[i];
    }

    int dp[n+1][s+1];
    zero(dp);
    dp[0][0] = (binpow(2,n,mod)); 

    rep(i,0,n)
    {
        rep(j,0,s+1)
        {
            dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
            if ( j+a[i] <= s )
            {
                dp[i+1][j+a[i]] = (dp[i][j]*modinv(2,mod))%mod;
            }
        }
    }

    cout<<dp[n][s]<<endl;
}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}


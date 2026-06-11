#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define f(i,l,h) for(ll i=l;i<h;i++)
#define fr(i,h,l) for(ll i=h;i>=l;i--)

using namespace std;

typedef pair<ll,ll> pll;
const ll INF=(ll)(998244353);
typedef vector<ll> vll;

ll power(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res=(res*a)%INF;
        b>>=1;
        a=(a*a)%INF;
    }
    return res;
}

int main()
{
    //cout << "Hello world!" << endl;
    ll n,s;
    cin>>n>>s;
    ll a[n];
    f(i,0,n) cin>>a[i];
    ll dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=power(2,n);

    ll inv2=power(2,INF-2);
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=s;j++){
            if(j<a[i-1]){
                dp[i][j]=dp[i-1][j]%INF;
            }else{
                dp[i][j]=(dp[i-1][j] + (dp[i-1][j-a[i-1]]*inv2))%INF;
            }
        }
    }

    cout<<dp[n][s]<<endl;



    return 0;
}

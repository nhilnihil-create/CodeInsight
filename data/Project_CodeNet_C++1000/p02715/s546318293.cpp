#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define sz(a) (long long)((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout<<"----------------------------------\n";
#define mp make_pair
#include <iostream>
#define fastinput ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


LL POW(LL x,LL y)
{
    LL ans=1;
    LL base=x;
    while(y)
    {
        if(y&1)
        {
            ans*=base;
            ans%=MOD;
        }
        base=base*base;
        base%=MOD;
        y=y>>1;
    }
    return ans;
}

int main()
{    
    fastinput;
    LL n,i,j,k,t,temp;
    cin>>n>>k;
    vector<LL> dp(k+1,0);

    for(i=k;i>=1;i--)
    {
       // debug(i);
        LL add=(k/i);
        dp[i]=POW(add,n);
        for(j=2*i;j<=k;j+=i)
        {
            //debug(j);
            dp[i]=(dp[i]-dp[j]+50*MOD)%MOD;
        }
       // part;
    }
    LL ans=0;
    for(i=1;i<=k;i++)
    {
        //debug(dp[i]);
        ans+=i*dp[i];
        ans%=MOD;
    }
    cout<<ans<<endl;
    


    
    return 0;
}


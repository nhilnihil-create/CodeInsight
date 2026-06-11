#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
string s;
int n;
ll po[200000];
#define MOD 1000000007
ll dp[200000][20];
ll sol(int i,int rem)
{
    ll ans = 0;
    if(i>=n)
    {
         //cout << i << " " << rem << endl;
        if(rem == 5)return 1;
        else return 0;
    }
    if(dp[i][rem] != -1)return dp[i][rem];
    if(s[i] == '?')
    {
        for(int j=0; j<10; j++)
        {
            ans = (ans+sol(i+1,((po[i]*j)%13+rem)%13))%MOD;
        }
    }
    else
    {
        ans = (ans+sol(i+1,((po[i]*(s[i]-'0'))%13 + rem)%13))%MOD;
    }

    return dp[i][rem] = ans;
}
int main()
{
    cin >> s;

    n = s.size();
    po[0] = 1;
    for(int i=1; i<n; i++)
    {
        po[i] = (10*po[i-1])%13;
    }
    reverse(po,po+n);
    memset(dp,-1,sizeof dp);
    ll fin = 0;
    if(s[0] == '?')
    {
        for(int i=0; i<10; i++)
        {
            fin = (fin+sol(1,(po[0]*i)%13))%MOD;
        }
    }
    else fin = sol(1,(po[0]*(s[0]-'0'))%13);

    cout << fin << endl;
}

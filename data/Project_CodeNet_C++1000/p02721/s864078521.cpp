#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int dps[200000];
int dpe[200000];
int dp[200000];
bool ans[200000];
int32_t main() {
    nitin;
    int n,k,c;
    cin>>n>>k>>c;
 string s; cin>>s;
    for(int i=0;i<n;i++)
    {
        ans[i]=true;
        if(i>=1)
        dps[i]=dps[i-1];
        if(s[i]=='o')
        {
            dps[i]=max(dps[i],(int)1);
            if(i>=c+1)
            dps[i]=max(dps[i-c-1]+1,dps[i]);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i+1<n)
        dpe[i]=dpe[i+1];
        if(s[i]=='o')
        {
            dpe[i]=max(dpe[i],(int)1);
            if(i+c+1<n)
                dpe[i]=max(dpe[i+c+1]+1,dpe[i]);
        }
    }
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='o')
        {
            int op1=0,op2=0;
            if(i-c-1>=0)
                op1=dps[i-c-1];
            if(i+c+1<n)
                op2=dpe[i+c+1];
            dp[i]=op1+op2+1;
        }
    }
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        if(i-c-1>=0)
        {
            m[dp[i-c-1]]--;
            if(m[dp[i-c-1]]==0)
                m.erase(dp[i-c-1]);
        }
        if(m.count(dp[i]))
            ans[i]=false;
        m[dp[i]]++;

    }
    m.clear();

    for(int i=n-1;i>=0;i--)
    {
        if(i+c+1<n)
        {
            m[dp[i+c+1]]--;
            if(m[dp[i+c+1]]==0)
                m.erase(dp[i+c+1]);
        }
        if(m.count(dp[i]))
        {
            ans[i]=false;
        }
        m[dp[i]]++;

    }

    for(int i=0;i<n;i++)
    {
        if(ans[i] && dp[i]==k)
            cout<<i+1<<endl;
    }
    return 0;
}
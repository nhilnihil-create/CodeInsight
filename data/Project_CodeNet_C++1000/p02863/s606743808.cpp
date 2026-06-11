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
int n,t;
pair<int,int> tr_f[3001];
int dp[3001][3001];
int solve(int idx,int bacha_hua)
{
    if(idx==n)
    {
        return 0;
    }
    if(bacha_hua<=0)
        return 0;
    if(dp[idx][bacha_hua]!=-1)
        return dp[idx][bacha_hua];
    int op1=solve(idx+1,bacha_hua);
    int op2=solve(idx+1,bacha_hua-tr_f[idx].first)+tr_f[idx].second;
    return dp[idx][bacha_hua]=max(op1,op2);
}
int32_t main() {
    nitin;
    for(auto &c:dp) for(auto &d:c) d=-1;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>tr_f[i].first>>tr_f[i].second;
    }
    sort(tr_f,tr_f+n);
//    for(int i=0;i<n;i++)
//    {
//        cout<<tr_f[i].first<<" "<<tr_f[]
//    }
    cout<<solve(0,t)<<endl;
    return 0;
}
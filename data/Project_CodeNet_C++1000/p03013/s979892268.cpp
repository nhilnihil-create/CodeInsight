#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n,dp[MAX][2],m;
ll mark[MAX];
ll recur(int pos,int last)
{
   // cout<<pos<<" "<<last<<endl;
    if(mark[pos] || pos>n)
        return 0;

    if(pos==n)
        return 1;
    ll &ret=dp[pos][last];
    if(~ret)
        return ret;
    ret=0;
    ret+=recur(pos+1,1);
    ret%=MOD;
    ret+=recur(pos+2,2);
    ret%=MOD;
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a;
        cin>>a;
        mark[a]=1;
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0)<<endl;

    return 0;
}

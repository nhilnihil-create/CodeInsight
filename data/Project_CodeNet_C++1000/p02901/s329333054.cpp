#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MODADD(ADD_X,ADD_Y)  (ADD_X+ADD_Y)%MOD;
#define MODSUB(SUB_X,SUB_Y)  (SUB_X-SUB_Y)+MOD)%MOD;
#define MODMUL(MUL_X,MUL_Y)  (MUL_X*MUL_Y)%MOD;
#define LCM(LCM_X,LCM_Y) (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e7;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
int arr[20],cost[1050],keys[1050];
int dp[1005][1<<13],n,m;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
bool check(int N,int pos)
{
    return (bool) (N & (1<<pos));
}
int bitmask(int pos,int mask)
{
    if(pos==m)
    {
        if(mask==((1<<n)-1))
            return 0;
        return 1e8;
    }
    int &ret=dp[pos][mask];
    if(~ret)
        return ret;
    ret=bitmask(pos+1,mask);
    ret=min(ret,cost[pos]+bitmask(pos+1,mask|keys[pos]));
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    priority_queue<pair<int,int> >pq;
    for(int i=0; i<m; i++)
    {
        cin>>cost[i];
        int a;
        cin>>a;
        for(int j=0; j<a; j++)
        {
            int b;
            cin>>b;
            keys[i]|=1<<(b-1);
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans=bitmask(0,0);
    if(ans==1e8)
        ans=-1;
    cout<<ans<<endl;

    return 0;
}

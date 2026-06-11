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
const int MAX = 3e5+15;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
const int base = 1337;
const int base1 = 1931;
ll pw[MAX+50];
ll pw1[MAX+50];
ll HASH[MAX+50];
ll HASH1[MAX+50];
void pre_power()
{
    pw[0] = 1;
    pw1[0] = 1;
    for(int i = 1; i < MAX; i++)
    {
        pw[i] = (pw[i - 1] * base) % MOD;
        pw1[i] = (pw1[i - 1] * base1) % MOD;
    }
}
ll get_hashval(string str)
{
    int len=str.length();
    ll hash_val=0;
    ll hash_val1=0;
    for(int i = 0; i < len; i++)
    {
        hash_val=((hash_val*base)+str[i])%MOD;
        HASH[i+1]=hash_val;
        hash_val1=((hash_val1*base1)+str[i])%MOD;
        HASH1[i+1]=hash_val1;
    }
    return hash_val;
}
ll SubstringHash(int l, int r)
{
    return (HASH[r] - (HASH[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}
ll SubstringHash1(int l, int r)
{
    return (HASH1[r] - (HASH1[l - 1] * pw1[r - l + 1]) % MOD + MOD) % MOD;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    pre_power();
    int n;
    string s;
    cin>>n;
    cin>>s;
    ll temp=get_hashval(s);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1,f=0;
        map<int,int>mp;
        map<int,int>mp1;
        for(int i=1; i<=n-mid+1; i++)
        {
            int cur=SubstringHash(i,i+mid-1);
            int cur1=SubstringHash1(i,i+mid-1);
            //  cout<<mid<<"    "<<i<<" "<<i+mid-1<<" "<<cur<<" "<<cur1<<endl;
            if(mp[cur] && mp[cur]<i && mp1[cur1] && mp[cur1]<i)
            {
                f=1;
                break;
            }
            if(!mp[cur])
                mp[cur]=i+mid-1;
            if(!mp1[cur1])
                mp1[cur1]=i+mid-1;
        }
        if(f)
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    cout<<ans<<endl;



    return 0;
}

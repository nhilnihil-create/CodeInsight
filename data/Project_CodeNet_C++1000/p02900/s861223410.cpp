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
bool mark[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll a,b;
    cin>>a>>b;
    map<ll,int>mp;
    vector<ll>v;
    ll sq=sqrt(a);
    for(int i=1; i<=sq; i++)
    {
        if(a%i==0)
        {
            ll c=a/i;
            if(c!=i)
                mp[c]++;
            mp[i]++;
        }
    }
    sq=sqrt(b);
    for(int i=1; i<=sq; i++)
    {
        if(b%i==0)
        {
            ll c=b/i;
            if(c!=i && mp[c])
                v.push_back(c);
            if(mp[i])
                v.push_back(i);
        }
    }
    int ans=0,sz=v.size(),cnt=v.size();
    for(int i=0; i<sz; i++)
    {
       if(v[i]==1)
        continue;
        for(int j=0; j<sz; j++)
        {
            if(i==j || mark[j])
                continue;
            if(v[j]%v[i]==0)
                mark[j]=1,cnt--;
        }
    }
    cout<<cnt<<endl;

    return 0;
}

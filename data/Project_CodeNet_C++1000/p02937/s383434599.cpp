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
const int MAX = 1e6;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
vector<int>pos[30];
int sz[30];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll f1[30]= {0},f2[30]= {0};
    string x,y;
    cin>>x>>y;
    ll l1=x.length();
    ll l2=y.length();
    for(int i=0; i<l1; i++)
    {
        f1[x[i]-'a']++;
        pos[x[i]-'a'].push_back(i);
        sz[x[i]-'a']++;
    }
    for(int i=0; i<l2; i++)
    {
        f2[y[i]-'a']++;
    }
    for(int i=0; i<26; i++)
    {
        if(f2[i] && !f1[i])
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    ll it=-1;
    ll ans=0;
    for(int i=0; i<l2; i++)
    {
        int cur=y[i]-'a';
        int l=0,r=sz[cur]-1,res=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(pos[cur][mid]>it)
            {
                res=pos[cur][mid];
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(res==-1)
        {

            ans+=l1;
            it=pos[cur][0];
        }
        else
            it=res;
    }
    ans+=it+1;
    cout<<ans<<endl;





    return 0;
}

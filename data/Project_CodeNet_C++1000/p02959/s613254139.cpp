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
const int MAX = 1e5+10;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
int arr[MAX],monster[MAX],hero[MAX],n,m;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    m=n+1;
    for(int i=0; i<m; i++)
    {
        cin>>monster[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>hero[i];
    }
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        if(monster[i]>hero[i])
            ans+=hero[i],hero[i]=0;
        else
        {
            ans+=monster[i];
            hero[i]-=monster[i];

        }
        if(i+1<=n)
        {
            if(monster[i+1]>hero[i])
                ans+=hero[i],monster[i+1]-=hero[i];
            else
            {
                ans+=monster[i+1];
                monster[i+1]=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

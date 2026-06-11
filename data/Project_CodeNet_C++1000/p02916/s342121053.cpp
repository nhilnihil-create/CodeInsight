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
int x[50],y[50],z[50];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>y[i];
    }
    for(int i=1; i<n; i++)
    {
        cin>>z[i];
    }

    int last=x[1],sum=y[x[1]];
    for(int i=2; i<=n; i++)
    {
        int cur=x[i];
        sum+=y[cur];
        if(last<cur && (cur-last)==1)
        {
            sum+=z[last];
        }
        last=cur;
    }
    cout<<sum<<endl;

    return 0;
}

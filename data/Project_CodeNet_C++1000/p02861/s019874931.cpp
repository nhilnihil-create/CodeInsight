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
int x[20],y[20],n;
double fact,sum;
double dist(double a,double b,double c,double d)
{
    double e=((a-c)*(a-c))+((b-d)*(b-d));
    return sqrt(e);
}
void recur(int used[],int last,double cur)
{
    int f=0;
    for(int i=1; i<=n; i++)
    {
        if(used[i]==0)
        {
            cur+=dist(x[i],y[i],x[last],y[last]);
            used[i]=1;
            recur(used,i,cur);
            used[i]=0;
            cur-=dist(x[i],y[i],x[last],y[last]);
            f=1;
        }
    }
    if(!f){
        sum+=cur;
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    fact=1;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
        fact*=i;
    }
    int used[20]= {0};
    for(int i=1; i<=n; i++){
        used[i]=1;
        recur(used,i,0);
        used[i]=0;
    }
    cout<<setprecision(10)<<fixed<<(sum/fact)<<endl;
    return 0;
}

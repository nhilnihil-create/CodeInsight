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
int pos[2000],marked[2000];
vector<int>v[2000];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<n; j++)
        {
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    int i,cnt=0;
    for(i=1; i<=100000000; i++)
    {
        int f=1;
        for(int j=1; j<=n; j++)
        {
            if(marked[j]==i)
                continue;
            int x=j;
            int posx=pos[x];
            if(posx==(n-1))
                continue;
            int valx=v[x][posx];
           // cout<<x<<" "<<valx<<endl;
            int y=valx;
            int posy=pos[y];
            if(posy==(n-1))
                continue;
            int valy=v[y][posy];
           // cout<<y<<" "<<valy<<endl;
            if(x==valy && marked[y]!=i )
            {
                pos[x]++;
                pos[y]++;
               //cout<<pos[x]<<" "<<pos[y]<<" "<<x<<" "<<y<<" "<<i<<endl;
                marked[x]=i;
                marked[y]=i;
                if(pos[x]==(n-1))
                    cnt++;
                if(pos[y]==(n-1))
                    cnt++;
                f=0;
            }

        }
        if(cnt==n)
            break;
        if(f)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<i<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define PI          acos(-1)
#define INF         100000000
#define sc(n)       scanf("%d",&n);
#define ssc(n)      scanf("%s",n);
#define lsc(n)      scanf("%lld",&n);
#define dsc(n)      scanf("%lf",&n);
#define csc(n)       scanf("%c",&n);
#define LL          long long int
#define UI          unsigned int
#define ULL         unsigned long long int
#define DB          double
#define pii         pair<int,int>
#define VI          vector<int>
#define MII         map<int,int>
#define PB          push_back
#define MP          make_pair
#define M(mx,a)     mx=max(mx,a)
#define IT          ::iterator
#define all(a)      a.begin(),a.end()
#define mems(a,b)   memset(a,b,sizeof(a))
#define F(i,a,b)    for(i=a;i<b;i++)
#define IN(n,aa)    for(i=0;i<n;i++)scanf("%d",&aa[i]);
#define PNT(n,aa)   for(i=0;i<n;i++)printf("%lld ",aa[i]);
#define mod         1000000007
#define NUM         100009
#define NUM2        1000000000


int aa[NUM][65];
LL dd[NUM][65];

void ffff()
{
    int i,j;
    LL a=1;
    for(i=1;i<NUM;i++)
    {
        for(j=0;j<10;j++)aa[i][j]=a*j%13;
        a=a*10%13;
    }
}

int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n,i,j,k;
        string ss;
        cin >> ss;
        reverse(all(ss));
        ffff();
        mems(dd,0);
        dd[0][0]=1;
        n=ss.size();
        for(i=0;i<n;i++)
        {
            if(isdigit(ss[i]))
            {
                for(j=0;j<13;j++)
                {
                    dd[i+1][(aa[i+1][ss[i]-'0']+j)%13]=dd[i][j];
                }
            }
            else
            {
                for(j=0;j<10;j++)
                {
                    for(k=0;k<13;k++)
                    {
                        LL ii=(aa[i+1][j]+k)%13;
                        dd[i+1][ii]=(dd[i+1][ii]+dd[i][k])%mod;
                    }
                }
            }
        }
        cout << dd[n][5] << endl;
    }
}

//printf("Case %d: ",++QQ);

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
#define NUM         2009
#define NUM2        1000000000


LL dd[NUM][NUM];

int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n,m,i,j,k,sm=0;
        sc(n);sc(m);
        int aa[n],bb[m];
        for(i=1;i<=n;i++)sc(aa[i]);
        for(i=1;i<=m;i++)sc(bb[i]);
        mems(dd,0);
        for(i=1;i<=n;i++)
        {
            sm=0;
            for(j=1;j<=m;j++)
            {
                sm+=dd[i-1][j];
                sm%=mod;
                if(aa[i]==bb[j])
                {
                    dd[i][j]=sm+1;
                    dd[i][j]%=mod;
                }
                else
                {
                    dd[i][j]=dd[i-1][j];
                }
            }
        }
        LL ans=0;
        for(i=1;i<=m;i++)
            ans+=dd[n][i],ans%=mod;
        cout << ans+1 ;
    }
}

//printf("Case %d: ",++QQ);

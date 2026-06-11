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
#define NUM         10000009
#define NUM2        1000000000


int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n;
        cin >> n;
        n++;
        int i,j,k;
        LL sm=0,smm=0;
        int aa[n],bb[n],aaa[n],bbb[n];
        for(i=0;i<n;i++)
        {
            sc(aa[i]);
            aaa[n-i-1]=aa[i];
        }
        for(i=0;i<n-1;i++)
        {
            sc(bb[i]);
            bbb[n-i-2]=bb[i];
        }
        for(i=0;i<n-1;i++)
        {
            if(bb[i]<aa[i])sm+=bb[i];
            else
            {
                sm+=aa[i];
                bb[i]-=aa[i];
                if(bb[i]>aa[i+1])sm+=aa[i+1],aa[i+1]=0;
                else sm+=bb[i],aa[i+1]-=bb[i];
            }
        }
        for(i=0;i<n-1;i++)
        {
            if(bbb[i]<aaa[i])smm+=bbb[i];
            else
            {
                smm+=aaa[i];
                bbb[i]-=aaa[i];
                if(bbb[i]>aaa[i+1])smm+=aaa[i+1],aaa[i+1]=0;
                else smm+=bbb[i],aaa[i+1]-=bbb[i];
            }
        }
        cout << max(sm,smm) ;
    }
}

//printf("Case %d: ",++QQ);

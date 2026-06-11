#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<string.h>
#define fornt(k,n) for(int i=k; i<n; ++i)
#define fornt2(p,n) for(int j=p; j<n; ++j)
#define pb push_back
#define ll long long
#define sc(n) scanf("%d",&n)
#define sc2(x,y) scanf("%d %d",&x,&y)
#define scl(n) scanf("%lld",&n)
#define scl2(x,y) scanf("%lld %lld",&x,&y)
#define pr(n) printf("%d\n",n)
#define prl(n) printf("%lld\n",n)
#define pry printf("YES\n")
#define prn printf("NO\n")
using namespace std;


int main ()
{
    int n,m,k,ans(0);
    sc2(n,m);
    sc(k);
    char a[n][m];
    fornt(0,n)
    {
        fornt2(0,m)
        {
            cin>>a[i][j];
        }
    }
    fornt(0,(1 << n))
    {
        fornt2(0,(1 << m))
        {
            int c=0;
            for(int c1 = 0; c1<n; c1++)
            {
                for(int c2 = 0; c2<m; c2++)
                {
                    if((i & (1 << c1)) && (j & (1 << c2)))
                    {
                        if(a[c1][c2]=='#')
                            ++c;
                    }
                }
            }
            if(c==k)
                ++ans;
        }
    }
    pr(ans);
}

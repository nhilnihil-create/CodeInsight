#include<bits/stdc++.h>
#define scan($) scanf("%d",&$)
#define test() int $;scan($);while($--)
using namespace std;
int gcd(int p, int q)
{
    if(p % q == 0)
        return q;
    return gcd(q, p % q);
}

int main()
{
    int n;
    int ans =0;
    scan(n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
            {
                ans+=gcd(gcd(i,j),k);
            }
    cout<<ans<<'\n';
    return 0;
}

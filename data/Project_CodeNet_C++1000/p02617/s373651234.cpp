#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define EPS 0.00000000001
#define INF 998244353
int main()
{
    int n,i,u,v;
    scanf("%d",&n);
    long long temp,ans=n+2;
    ans=ans*(n+1);
    ans=ans*n/6;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        temp=n+1-v;
        temp=temp*u;
        ans=ans-temp;
    }
    printf("%lld",ans);
    return 0;
}

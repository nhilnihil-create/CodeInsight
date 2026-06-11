#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,v,b,w,t;
    scanf("%lld%lld%lld%lld%lld",&a,&v,&b,&w,&t);
    if(v*t-w*t>=fabs(a-b))
        printf("YES\n");
    else printf("NO\n");
}

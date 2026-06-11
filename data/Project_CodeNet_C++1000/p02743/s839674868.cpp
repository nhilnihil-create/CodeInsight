#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(c<a+b) puts("No");
    else if((c-a-b)*(c-a-b)>4*a*b) puts("Yes");
    else puts("No");
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    ll a,b,k;
    scanf("%lld%lld%lld",&a,&b,&k);
    if (a>=k)
    printf("%lld %lld\n",(a-k),b);
    else if ((a+b)>=k)
    printf("0 %lld\n",(b-(k-a)));
    else
    printf("0 0\n");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#include<math.h>
typedef long long int ll;

int main()
{
    ll n, i, temp, z, mx1=0,mx2=0,i1,i2;
    scanf("%lld", &n);
    ll ara[n];
    for(i=0;i<n;i++){
        scanf("%lld", &ara[i]);
        if(ara[i]>mx1){
            mx1 = ara[i];
            i1 = i;
        }
    }
    sort(ara,ara+n);
    for(i=0;i<n;i++){
        if(i==i1) printf("%lld\n", ara[n-2]);
        else printf("%lld\n", ara[n-1]);
    }
    return 0;
}
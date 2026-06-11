#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;

ll n,ans;

int main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i)
        ans=(ans+(n-i+1)*(1-i)+(i+n)*(n-i+1)/2);
    for (int i=1;i<n;++i){
        int u,v;scanf("%d%d",&u,&v);
        if (u>v) swap(u,v);
        ans-=(1ll*u*(n-v+1));
    }
    printf("%lld\n",ans);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;

ll n,a[200007],sum,res;

int main() {
    scanf("%lld",&n);res=n-1;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    sum=a[n],res--;
    for (int i=n-1;i;--i){
        if (res) sum+=a[i],--res;
        if (res) sum+=a[i],--res;
        if (!res) break;
    }
    printf("%lld\n",sum);
    return 0;
}

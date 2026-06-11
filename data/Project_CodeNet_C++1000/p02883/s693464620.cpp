#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
long long k,mid;
int a[300000],f[300000];

bool check()
{
    long long tk = k;
    for(int i=0;i<n;++i){
        if(1LL*a[i]*f[i]>mid){
        long long ts = mid/f[i];
        tk -= a[i] - ts;
        }
        if(tk<0) return false;
    }
    return true;
}

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)scanf("%d",f+i);
    sort(f,f+n);
    sort(a,a+n);reverse(a,a+n);
    long long l=0,r = 1000000;
    r*=r;
    while(l<r){
        mid = (l+r)/2;
        if(check())r=mid;
        else l = mid + 1;
    }
    printf("%lld\n",l);
    return 0;
}

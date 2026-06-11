#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,n,m,s;
    cin>>n;s=0;
    long long a[n+3],b,c[n+3];
    for(i=0;i<=n;i++) scanf("%lld",&a[i]);
    for(i=0;i<n;i++){
        scanf("%lld",&b);
        if(b>=a[i]){s+=a[i];b-=a[i];}
        else {s+=b;b=0;}
        if(b>=a[i+1]){s+=a[i+1];a[i+1]=0;}
        else {s+=b;a[i+1]-=b;}
    } printf("%lld",s);
}

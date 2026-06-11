#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll n,a[maxn],b[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]*=2;

    ll sum=0;
    for(int i=1;i<=n;i++)
        if(i%2)sum+=a[i];
        else sum-=a[i];

    b[1]=sum/2;
    printf("%lld",b[1]);

    for(int i=2;i<=n;i++){
        b[i]=a[i-1]-b[i-1];
        printf(" %lld",b[i]);
    }
    printf("\n");

    return 0;
}


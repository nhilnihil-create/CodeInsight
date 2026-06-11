#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[200010];
int main() {
    ll sum=0,n;
    cin>>n;
    for(ll i=1;i<=n;i++)    cin>>a[i],sum^=a[i];
    for(ll i=1;i<=n;i++)    printf("%d ",sum^a[i]);
    return 0;
}

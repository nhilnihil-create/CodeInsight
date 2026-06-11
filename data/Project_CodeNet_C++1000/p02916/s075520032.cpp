#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,n,m,s;
    cin>>n;
    long long a[n+3],b[n+3],c[n+3];
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<=n-1;i++) cin>>c[i];
    s=b[a[1]];
    for(i=2;i<=n;i++){
        s+=b[a[i]];
        if(a[i-1]+1==a[i]) s+=c[a[i-1]];
    }cout<<s;
}

#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0,d;
    cin>>n;
    long long a[n+1],b[n],f[n+1][n+1];
    f(i,0,n+1){
        cin>>a[i];
    }
    f(i,0,n+1){
        cin>>b[i];
    }
    f2(i,n-1,-1){
        d=min(a[i+1],b[i]);
        ans+=d;
        b[i]-=d;
        d=min(a[i],b[i]);
        ans+=d;
        a[i]-=d;
    }
    cout<<ans<<endl;
    return 0;
}

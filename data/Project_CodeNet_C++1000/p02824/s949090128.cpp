#include <bits/stdc++.h>
using namespace std;
long long a[100001];

int ans;
long long n,m,v,p;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false); 
    cin>>n>>m>>v>>p;
    int i,j;
    for(i=1 ; i<=n ; i++)cin>>a[i];
    sort(a+1,a+n+1);

    ans=p;
    long long s=0;
    for(i=n-p ; i>=1 ; i--){
        s+=a[i+1];
        if(a[i]+m>=a[n-p+1]){
            if(1ll*m*(i+p-1)+1ll*(n-p-i+1)*(a[i]+m)-s>=1ll*m*v)ans++;
        }

    }
    cout<<ans;
    return 0;
}
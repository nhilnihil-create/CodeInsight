#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+69;
int a[MAXN];
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i=1;i<=m;i++)ans+=a[i];
    cout<<ans;
}

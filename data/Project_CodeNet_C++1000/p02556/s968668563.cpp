#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=2e5+5;
int a[maxm];
int b[maxm];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        a[i]=x-y;
        b[i]=x+y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans=max(a[n]-a[1],b[n]-b[1]);
    cout<<ans<<endl;
    return 0;
}
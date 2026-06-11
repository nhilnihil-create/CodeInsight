#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=1e5+5;
int d[1<<15];
int a[maxm];
int b[maxm];
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        int k;cin>>k;
        int t=0;
        while(k--){
            int x;cin>>x;x--;
            t|=(1<<x);
        }
        b[i]=t;
    }
    for(int i=0;i<(1<<n);i++)d[i]=1e18;
    d[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=(1<<n)-1;j>=0;j--){
            d[j|b[i]]=min(d[j|b[i]],d[j]+a[i]);
        }
    }
    int ans=d[(1<<n)-1];
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;
    return 0;
}
/*


*/

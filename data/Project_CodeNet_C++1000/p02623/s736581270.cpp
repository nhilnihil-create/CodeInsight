#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[200005],b[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long tot=0;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        tot+=b[i];
    }
    int ans=0;
    for(int ia=0,ib=m;ia<=n;ia++){
        tot+=a[ia];
        while(tot>k&&ib>0)tot-=b[ib--];
        if(tot>k)break;
        ans=max(ans,ia+ib);
    }
    cout<<ans<<endl;

return 0;
}
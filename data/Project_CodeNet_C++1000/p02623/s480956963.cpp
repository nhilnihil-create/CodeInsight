#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m,k;
ll a[200005];
ll b[200005];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]+a[i-1];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        b[i]=b[i]+b[i-1];
    }
    int j=m;
    int rj=0;
    for(int i=0;i<=n;i++){
        ll t=k-a[i];
        if(t<0)
            break;
        for(j;j>=0;j--)
            if(b[j]<=t)
                break;
        rj=max(rj,i+j);
    }
    cout <<rj<<endl;
}

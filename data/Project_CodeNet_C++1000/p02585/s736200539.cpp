#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll p[n],c[n];
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++) cin>>c[i];
    vector<ll>maxin[n];
    vector<ll>real[n];
    for(int i=0; i<n; i++) {
        ll ans=0,mx=-1e18,cur=p[i];
        while(1) {
            ans+=c[cur-1];
            mx=max(mx,ans);
            maxin[i].push_back(mx);
            real[i].push_back(ans);
            cur=p[cur-1];
            if(cur==p[i])break;
        }
    }
    ll ans=-1e18;
    for(int i=0; i<n; i++) {
        long long int t=k%maxin[i].size();
        ll s=real[i].size();
        ll e;
        if(t==0) e=0;
        else e=maxin[i][t-1];
        ll y=0;
        if(k/s>1)
            y=real[i][s-1]*(k/s-1)+maxin[i][s-1];
        if(k<=s) ans=max(ans,maxin[i][k-1]);
        else ans=max(ans,max(real[i][s-1]*(k/s)+e,
                                 max(y,maxin[i][s-1])));
    }
    cout<<ans<<endl;
    return 0;
}

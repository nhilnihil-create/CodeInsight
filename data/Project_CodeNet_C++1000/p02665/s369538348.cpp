#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int n;
    cin>>n; n++;
    ll a[100001];
    rep(i, n) cin>>a[i];

    bool ng=true;
    rep(i, n) if(a[i]!=0) ng=false;
    if(ng){   
        cout<<(-1)<<endl;
        return 0;
    }

    ll mx[100001];
    mx[0]=1;
    rep(i, n){
        if(mx[i]<a[i]){
            cout<<(-1)<<endl;
            return 0;
        }
        if(i<n-1){
            mx[i+1]=(mx[i]-a[i])*2;
            mx[i+1]=min(mx[i+1], LLONG_MAX/4);
        }
    }

    ll ans=0;
    ll cmx=0;
    for(int i=n-1; i>=0; i--){
        ll cmx=min(mx[i], cmx+a[i]);
        ans+=cmx;
    }

    cout << ans << endl;
    return 0;
}

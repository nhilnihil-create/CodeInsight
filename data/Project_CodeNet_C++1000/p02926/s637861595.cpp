#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main(){
    cout<<fixed<<setprecision(16);
    ll n;
    cin>>n;
    vector<ll> sx(n),sy(n);
    vector<pair<double,ll>> a(n);
    double mx=0;
    double my=0;
    rep(i,n){
        cin>>sx[i]>>sy[i];
        double ang=450-atan2(sx[i],sy[i])*180/acos(-1);
        if(ang>=360)ang-=360;
        a[i]=make_pair(ang,i);
        mx+=sx[i];
        my+=sy[i];
    }
    sort(a.begin(),a.end());
    double ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            double x=0;
            double y=0;
            for(ll k=i;k<=j;k++){
                x+=sx[a[k].second];
                y+=sy[a[k].second];
            }
            ans=max(ans,sqrt(x*x+y*y));
            ans=max(ans,sqrt((mx-x)*(mx-x)+(my-y)*(my-y)));
        }
    }
    cout<<ans<<endl;
}

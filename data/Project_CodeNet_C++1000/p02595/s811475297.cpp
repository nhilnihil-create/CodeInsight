#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d;
    cin>>n>>d;
    ll cnt=0;
    for(ll i=0;i<n;++i){
        ll x,y;
        cin>>x>>y;
        if(x<0) x*=-1;
        if(y<0) y*=-1;
        long double dist = sqrt((x*x)+(y*y));
        //cout<<x<<" "<<y<<" "<<dist<<endl;
        if(dist<=d) {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
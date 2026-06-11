#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector <ll> a(n);
    ll go=0;
    rep(i,n){
        cin >> a[i];
        go+=a[i];
    }

    sort(a.begin(),a.end());

    priority_queue <ll> q;

    for (ll i=1; i*i<=go; ++i){
        if(go%i==0){
            q.push(i);
            q.push(go/i);
        }
    }

    ll qq;
    ll k2=0,k3;
    ll wa=0;
    ll ans;
    vector <ll> pl,pl2;
    while(q.size()!=0){
        qq=q.top();
        q.pop();
        
        wa=0;
        k2=0;
        pl=pl2;
        rep(i,n){
            if(a[i]%qq!=0){
            k2+=qq-(a[i]%qq);
            pl.push_back(qq-(a[i]%qq));
            wa+=(a[i]/qq+1)*qq;
            }
            else{
                wa+=a[i];
                pl.push_back(0);
            }
        }
        sort(pl.rbegin(),pl.rend());
        k3=(wa-go)/qq;
        rep(i,k3){
            k2-=pl[i];
        }

        //cout << qq << " " << k2 << endl;
        if(k2<=k){
            ans=qq;
            break;
        }

    }

    cout << ans << endl;
    

    return 0;
}
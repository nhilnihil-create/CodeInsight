#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<bool> a(n,false);
    rep(i,k){
        ll d; cin >> d;
        rep(j,d){
            ll e; cin >> e;
            e--;
            a[e]=true;
        }
    }
    ll ans=0;
    rep(i,n){
        if(a[i]==false) ans++;
    }
    cout << ans << endl;
}
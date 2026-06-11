#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll M = 1000000000000000000;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    bool flag = false;
    rep(i,n){
        cin >> a[i];
        if(a[i]==0) flag = true;
    }
    ll ans=1;
    rep(i,n){
        if(flag) {
            ans = 0;
            break;
        }
        if(a[i]>M/ans){
            ans = -1;
            break;
        }
        ans *= a[i];
    }
    cout << ans << endl;
}
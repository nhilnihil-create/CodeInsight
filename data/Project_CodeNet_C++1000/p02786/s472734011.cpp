#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll po(ll p, ll n){
    ll ans = 1;
    for(int i=0; i<n; ++i){ans *= p;}
    return ans;
}

int main(){
    ll h; cin >> h;
    if(h==1){cout << 1 << endl; return 0;}
    ll sum = 2, cnt = 0;
    while(1){
        if(h>=sum){sum *= 2; cnt++;}
        else{break;}
    }
    ll res = 1;
    for(ll i=1; i<=cnt; ++i){
        ll pp = 2;
        res += po(pp, i);
    }
    cout << res << endl;
    return 0;
}
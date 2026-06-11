#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll n, k;
vector<ll> a;

bool is_ok(ll x){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % x != 0){
            cnt += (a[i] / x);
        }
        else if(a[i] % x == 0){
            cnt += (a[i] / x) - 1;
        }
    }
    if(cnt <= k) return true;
    else return false;
}

int main(void){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ok = 1000000010;
    ll ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(is_ok(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    if(k != 0) cout << ok << endl;
    else{
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
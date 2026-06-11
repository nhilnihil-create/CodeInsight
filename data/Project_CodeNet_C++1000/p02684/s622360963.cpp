#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
        a[i]--;
    }
    vector<bool> v(n,false);
    ll now = 0;
    ll c = 0;
    ll x = 0;

    while (true){
        v[now] = true;
        c++;
        now = a[now];
        if (v[now]){
            x = now;
            break;
        }
    }
    //cout << x << endl;
    //cout << c << endl;
    now = 0;
    ll s = 0;
    while(true){
        if (now == x){
            break;
        }
        else{
            s++;
            now = a[now];
        }
    }
    //cout << s << endl;
    ll loop = c-s;
    ll z = (max(k-s,0LL))%loop;
    ll ans = 0;
    now = 0;
    if (k >= s){
        for (ll i = 0; i < s+z; i++){
            now = a[now];
        }
    }
    else{
        for (ll i = 0; i < k; i++){
            now = a[now];
        }
    }
    cout << now+1 << endl;
}

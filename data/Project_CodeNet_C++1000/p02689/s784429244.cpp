#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> h(n), a(m), b(m);
    vector<bool> ok(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
        ok[i] = true;
    }
    for(int i = 0; i < m; i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        if(h[a[i]-1] < h[b[i]-1]){
            ok[a[i]-1] = false;
        } else if(h[a[i]-1] > h[b[i]-1]){
            ok[b[i]-1] = false;
        } else {
            ok[a[i]-1] = false;
            ok[b[i]-1] = false;
        }
    }

    for(int i = 0; i < n; i++){
        if(ok[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}

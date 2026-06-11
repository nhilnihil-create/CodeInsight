#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < min(k, (ll)42); i++){
        ll d[n] = {0};
        for(int j = 0; j < n; j++){
            ll lb = max((ll)0, j - a[j]);
            ll ub = min(n, j + a[j]);
            d[lb]++;
            if(ub + 1 < n)
                d[ub + 1]--;
        }
        a[0] = d[0];
        for(int j = 1; j < n; j++){
            a[j] = d[j] + a[j - 1];
        }
    }
    for(int i = 0 ; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
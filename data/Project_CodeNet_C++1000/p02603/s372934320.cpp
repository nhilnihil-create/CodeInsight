#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ll n; cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
    ll ans = 1000, x;
    for(ll i = 1; i < n; ++i){
        if(arr[i] > arr[i - 1]){
            x = ans / arr[i - 1];
            ans -= (x * arr[i - 1]);
            ans += (x * arr[i]);
        }
    }
    cout << ans;
    return 0;
}

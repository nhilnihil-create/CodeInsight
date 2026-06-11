#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }

    ll tentou_1 = 0;
    for(ll i = 0;i < n - 1;i++){
        for(ll j = i + 1;j < n;j++){
            if(a[i] > a[j]){
                tentou_1++;
            }
        }
    }
    ll tentou_2 = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < n;j++){
            if(a[i] > a[j]){
                tentou_2++;
            }
        }
    }
    
    ll ans = tentou_1 * k % 1000000007;
    ans += tentou_2 * (((k - 1) * k) / 2 % 1000000007) % 1000000007;
    ans %= 1000000007;
    cout << ans;

    return 0;
}
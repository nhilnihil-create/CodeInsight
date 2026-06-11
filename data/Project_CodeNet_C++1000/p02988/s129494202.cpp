#include <bits/stdc++.h>

#define ll long long
#define N (ll)(2*1e5)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;


int main() {
    // 176 algorithm design manual
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;

    cin >> n;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    ll conta = 0;
    for(int i = 1; i < n-1; i++) {
        ll menor = min({arr[i-1], arr[i], arr[i+1]});
        ll maior = max({arr[i-1], arr[i], arr[i+1]});
        if(arr[i] != menor && arr[i] != maior)
            conta++;
    }
    cout << conta << endl;
    
    return 0;
}
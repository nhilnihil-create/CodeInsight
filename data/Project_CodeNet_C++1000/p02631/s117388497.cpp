#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll B=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        B^=a[i];
    }
    for(ll i=0;i<n;i++){
        cout << (B^a[i]) << " ";
    }
}

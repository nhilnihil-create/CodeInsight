#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ll cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[i] > a[j]) cnt1++;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i] > a[j]) cnt2++;
        }
    }
    ll m1 = k;
    ll m2 = (k * (k - 1) / 2) % mod;
    cout << (cnt1 * m1 + cnt2 * m2) % mod<< endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < n; i++){
        ll ans = sum ^ a[i];
        cout << ans << endl;
    }
}
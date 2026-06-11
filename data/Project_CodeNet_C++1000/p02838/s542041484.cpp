#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i=0; i<60; i++){
        long long x = 0;
        for(int j=0; j<n; j++){
            if(a[j]>>i&1) x++;
        }
        long long now = x*(n-x) % mod;
        for(int j=0; j<i; j++){
            now = now * 2 % mod;
        }
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
}
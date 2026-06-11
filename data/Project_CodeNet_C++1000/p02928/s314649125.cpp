#include <bits/stdc++.h>
typedef long long ll; 
typedef unsigned long long ull;
const ull mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

void solve() {
    int n, k; sc(n); sc(k);
    int a[n]; fo(i, n) sc(a[i]);
    int g = 0;
    int el = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) g++;
            else if (a[i] < a[j]) el++;
        } 
    }
    ull num1 = (ull) k * (k+1);
    num1 /= 2; num1 %= mod;
    ull num2 = (ull) k * (k-1);
    num2 /= 2; num2 %= mod;
    num1 *= (ull) g; num1 %= mod;
    num2 *= (ull) el; num2 %= mod;
    ull ans = (num1 + num2) % mod;
    cout << ans;
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
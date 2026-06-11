#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    ll mod = 1000000007;
    int n, m;
    cin >> n >> m;
    vector<bool> bre(n, false);
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        bre[a] = true;
        if(i > 0) {
            if(bre[a - 1] == true) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    vector<ll> fib(n);
    rep(i, n) {
        if(bre[i]) {
            fib[i] = 0;
            continue;
        }
        if(i == 0) {
            fib[i] = 1;
            continue;
        }
        if(i == 1) {
            fib[i] = fib[i - 1] + 1;
            continue;
        }
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i - 2] > mod) {
            fib[i] %= mod;
            fib[i - 1] %= mod;
            fib[i - 2] %= mod;
        }
    }
    cout << fib[n - 1] % mod << endl;
}
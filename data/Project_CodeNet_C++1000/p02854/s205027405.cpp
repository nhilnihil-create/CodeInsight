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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> rui(n);
    rep(i, n) {
        cin >> a[i];
        if(i > 0) {
            rui[i] += rui[i - 1] + a[i];
        }
        else rui[0] = a[0];
    }
    int key = 0;
    ll mi = 100000000000;
    rep(i, n) {
        if(abs(rui[i] * 2 - rui[n - 1]) < mi) {
            mi = abs(rui[i] * 2 - rui[n - 1]);
            key = i;
        }
    }
    ll cost = abs(rui[key] * 2 - rui[n - 1]);
    cout << cost << endl;
    
    
}
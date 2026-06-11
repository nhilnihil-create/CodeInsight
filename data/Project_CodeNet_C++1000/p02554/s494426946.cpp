#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <array>

#define rep(i, n) for (auto i = 0; i < (n); i++)

using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define bootstrap ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


void solve() {
    // A and B = All - ~A - ~B + ~(A or B)
    ll num;
    cin >> num;
    ll a = 1;
    ll b = 2;
    ll c = 1;
    ll mod = 1000000007;
    for (ll i = 0; i < num; i++) {
        a = (a * 10) % mod;
        b = (b * 9) % mod;
        c = (c * 8) % mod;
    }
    ll res = (a - b + c) % mod;
    if(res >= 0){
        cout << res;
    } else {
        cout << res + mod;
    }
}

int main() {
    bootstrap
    solve();
}

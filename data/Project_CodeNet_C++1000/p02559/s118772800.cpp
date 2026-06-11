#include <atcoder/all>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
using namespace atcoder;
int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ft.add(i, x);
    }
    for(int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t) {
            cout << ft.sum(a, b) << endl;
        } else {
            ft.add(a, b);
        }
    }
}
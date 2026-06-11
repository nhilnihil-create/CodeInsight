#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
ll ruijou (ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2) {
        return a * ruijou(a, n - 1) % mod;
    }
    else {
        ll k = ruijou(a, n/2);
        return k * k % mod;
    }
}
int main() {
    string l;
    cin >> l;
    ll ret = 0;
    ll bairitu = 1;
    int len = l.length();
    for (int i = 0; i < len; i++) {
        if (l[i] == '1') {
            ret += bairitu * ruijou (3, (len - i - 1));
            ret %= mod;
            bairitu *= 2;
            bairitu %= mod;
        }
        if (i == len - 1) {
            ret += bairitu;
            ret %= mod;
        }
    }
    cout << ret << endl;
    return 0;
}
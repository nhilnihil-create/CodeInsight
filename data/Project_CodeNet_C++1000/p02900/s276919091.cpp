#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, (a%b));
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll t = gcd(a, b);

    int cnt = 0;

    for(ll i = 2; i*i <= t; ++i) {
        if(t % i != 0) continue;
        ++cnt;
        while(t % i == 0) {
            t /= i;
        }
    }
    if(t != 1) ++cnt;

    cnt += 1;
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> p;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a == 0) {
            p.push_back(0);
            while (n % a == 0) {
                p.back()++;
                n /= a;
            }
        }
    }
    if (n != 1) p.push_back(1);
    int cnt = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        int num = 1;
        while (p[i] - num >= 0) {
            cnt++;
            p[i] -= num;
            num++;
        }
    }
    cout << cnt << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);  // n=6, i=2 => 3 を入れる. n=9, i=3 のときは除外.
            }
        }
    }
    return res;
}

ll calc(ll a, ll b) {
    return a * a * a * a * a - b * b * b * b * b;
}

int main() {
    ll X;
    cin >> X;

    vector<ll> dsrs = divisor(X);
    for (auto dr : dsrs) {
        ll a, b;
        b = -70;
        for (b = -70; b < 0; b++) {
            a = b + dr;
            if (a > 70 || a < 0) {
                continue;
            }
            if (calc(a, b) == X) {
                print(a, b);
                return 0;
            }
        }

        b = 0;
        a = dr;
        if (a > 70) {
            continue;
        }
        ll right = 5000;  //TODO
        ll left = 1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (mid - dr < 0) {
                left = mid + 1;
                continue;
            }
            ll r = calc(mid, mid - dr);
            if (r == X) {
                print(mid, mid - dr);
                return 0;
            } else if (r < X) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
}

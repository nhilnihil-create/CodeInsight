#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll n, a, b;
    cin >> n >> a >> b;
    ll cen = INF, right = INF, left = INF;
    if(abs(a - b) % 2 == 0) {
        cen = abs(a - b) / 2;
    }
    right = n - b + 1 + (b - a - 1) / 2;
    left = a - 1 + 1 + (b - a - 1) / 2;
    cout << min(cen, min(right, left));
}

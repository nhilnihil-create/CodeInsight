#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

ll a, b, n;

ll f(ll x) { // f(x)はbで周期するため、0 <= x < bで考えれば良く、この時、floor(x / b) = 0であるため、f(x) = floor(a * x / b) は、短調増加
    return a * x / b - a * (x / b);
}

int main() {
    cin >> a >> b >> n;
    cout << f(min(b-1, n)) << endl;
}
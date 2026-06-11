#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll a, b, k; cin >> a >> b >> k;
    ll eat_a = min(a, k);
    a -= eat_a;
    k -= eat_a;
    ll eat_b = min(b, k);
    b -= eat_b;
    k -= eat_b;

    printf("%lld %lld\n", a, b);
}
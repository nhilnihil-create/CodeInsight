#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll n;

ll f(ll a, ll b) {
    if (a > b) return f(b, a);

    if((b - a)&1) {
        auto g = [&](ll p1, ll p2) {
            return (p1 - 1) + (p2 - p1 + 1)/2;
        };

        return min(g(a, b), g(n - b + 1, n - a + 1));
    }
    else {
        return (b - a) >> 1;
    }
}

int main() {
    ll a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    printf("%lld\n", f(a, b));
    return 0;
}
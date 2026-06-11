#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
// can't

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll x;
    scanf("%lld", &x);

    ll a, b;
    bool found = false;
    for (a = -118; a <= 119; a++) {
        for (b = -118; b <= 119; b++) {
            if (pow(a, 5) - pow(b, 5) == x) found = true;
            if (found) break;
        }
        if (found) break;
    }

    printf("%lld %lld\n", a, b);
}
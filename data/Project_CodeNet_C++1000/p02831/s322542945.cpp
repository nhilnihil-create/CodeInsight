#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%lld", (ll)x * y / __gcd(x, y));
    return 0;
}

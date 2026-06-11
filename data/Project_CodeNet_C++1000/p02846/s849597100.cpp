#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    ll t1, t2, a1, a2, b1, b2, d1, d2, ans;

    scanf("%lld%lld%lld%lld%lld%lld", &t1, &t2, &a1, &a2, &b1, &b2);

    d1 = (a1 - b1) * t1;
    d2 = (a2 - b2) * t2;

    if (d1 > 0) {
        d1 = -d1;
        d2 = -d2;
    }

    if (d1 + d2 < 0) {
        printf("0\n");
        return 0;
    }

    if (d1 + d2 == 0) {
        printf("infinity\n");
        return 0;
    }

    ans = (-d1) / (d1 + d2) * 2 + 1;

    if ((-d1) % (d1 + d2) == 0) {
        ans--;
    }

    printf("%lld\n", ans);

    return 0;
}
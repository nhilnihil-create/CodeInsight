#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

void solve()
{
    int n, V, P; ll M;
    scanf("%d%lld%d%d", &n, &M, &V, &P);
    vector<ll> a(n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        ll cnt = (ll)M * ((ll)P+m);
        int bad = 0;
        for (i = m + 1; i <= n - P; i++) {
            if(a[m]+M-a[i]<0) bad=1;
            cnt += (a[m] + M - a[i]);
        }
        if (cnt >= (ll)M*V && bad==0) {
            r = m;
        }
        else {
            l = m;
        }
    }
    printf("%d\n", n-r);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d%d", &T, &B);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
ll a[N], r[N], l[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)scanf("%d", &a[i]);
    if (n == 0) {
        if (a[0] == 1)puts("1");
        else puts("-1");
        return 0;
    }
    for (int i = n; i >= 0; i--) {
        l[i] = a[i] + (l[i + 1] + 1) / 2;
        r[i] = a[i] + r[i + 1];
    }
    if (l[0] != 1) {
        puts("-1");
        return 0;
    }
    ll ans = 1, cur = 1;
    for (int i = 1; i <= n; i++) {
        cur -= a[i - 1];
        cur = min(cur * 2, r[i]);
        ans += cur;
    }
    printf("%lld\n", ans);
    return 0;
}
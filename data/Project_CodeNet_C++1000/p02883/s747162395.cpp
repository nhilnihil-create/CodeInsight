#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 2e5 + 100;
ll A[N], F[N];
ll n, k;
template <typename _tp>
inline void read(_tp& x) {
    char ch = getchar(), sgn = 0;
    x = 0;
    while (ch ^ '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') ch = getchar(), sgn = 1;
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    if (sgn) x = -x;
}
bool cheak(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (x / F[i] < A[n - i + 1]) {
            cnt += A[n - i + 1] - (x / F[i]);
        }
        if(cnt>k)return false;
    }
    return cnt <= k;
}

int main() {
    read(n),read(k);
    for (int i = 1; i <= n; i++) {
        read(A[i]);
    }
    sort(A + 1, A + n + 1);
    ll maxx = -1;
    for (int i = 1; i <= n; i++) {
        read(F[i]);
        maxx = max(maxx, F[i] * A[n - i + 1]);
    }
    sort(F + 1, F + n + 1);
    ll l = 0, r = maxx;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (cheak(mid))ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
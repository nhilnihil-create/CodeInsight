#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int inf = ~0u >> 1;
typedef pair<int, int> P;
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n)-1; i >= a; --i)
const ll mod = 1e9 + 7;
int fa[maxn];
ll cnt[maxn];
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int r1, int r2)  //合并两个集合，r2合并到r1
{
    r1 = find(r1);
    r2 = find(r2);
    if (r1 != r2) {
        fa[r2] = r1;
        cnt[r1] += cnt[r2];
        cnt[r2] = 0;
    };
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    REP(i, 1, n + 1) {
        fa[i] = i;
        cnt[i] = 1;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    ll ans = 0;
    REP(i, 1, n + 1) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll p = 1e9 + 7;
#define DEBUG(x) cout << (x) << '\n'
#define fi first
#define se second

int n, a[MAXN];
void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mx = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += max(0, mx - a[i]), mx = max(mx, a[i]);
    DEBUG(ans);
}
int main(){
#ifdef Irene
    freopen("in.txt", "r", stdin);
#endif // Irene
    ios_base::sync_with_stdio(false);

    run(); return 0;
}

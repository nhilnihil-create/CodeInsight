#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 200005
#define ll long long

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "
#else
#define debug(x) ;
#endif

int n, k;
int a[maxn];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = a[0]+k-a[n-1];
    for (int i = 1; i < n; i++)
        mx = max(mx, a[i] - a[i - 1]);
    cout << k - mx;

    return 0;
}
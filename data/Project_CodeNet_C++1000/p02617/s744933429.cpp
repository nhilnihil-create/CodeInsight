#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int u[200010], v[200010];
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n-1;i++) cin >> u[i] >> v[i];

    ans = 1LL*n*(n+1)*(n+2)/6;
    for (int i=0;i<n-1;i++) {
        if (u[i]>v[i]) swap(u[i], v[i]);
        ans -= 1LL*u[i]*(n-v[i]+1);
    }

    cout << ans << endl;
}

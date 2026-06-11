#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[200010], cnt[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;
    for (int i=1;i<=n;i++) ans += 1LL*cnt[i]*(cnt[i]-1)/2LL;

    for (int i=0;i<n;i++) cout << ans-cnt[a[i]]+1 << endl;
}

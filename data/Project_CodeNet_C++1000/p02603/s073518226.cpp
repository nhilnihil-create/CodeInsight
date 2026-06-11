#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll now = 1000, pv = 1000, cnt = 0;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        a.pb(x);
    }
    a.resize(unique(a.begin(), a.end())-a.begin());
    n = a.size();
    if (n==1) {
        cout << 1000 << endl;
        return 0;
    }

    if (a[0]<a[1]) {
        cnt = now/a[0];
        now -= a[0]*cnt;
    }
    for (int i=1;i<n-1;i++) {
        if (a[i-1]>a[i]&&a[i+1]>a[i]) {
            pv = now;
            cnt = now/a[i];
            now -= a[i]*cnt;
        }
        if (a[i-1]<a[i]&&a[i+1]<a[i]) {
            now += a[i]*cnt;
            cnt = 0;
        }
    }
    if (a[n-2]<a[n-1]) {
        now += a[n-1]*cnt;
        cnt = 0;
    }

    cout << max(pv, now) << endl;
}

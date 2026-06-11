#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> l(n);
    rep(i, n) cin >> l[i];
    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (l[i] == l[j]) continue;
            for (int k = j+1; k < n; k++) {
                if (l[i] == l[k]) continue;
                if (l[j] == l[k]) continue;
                ll maxEdge = 0;
                maxEdge = max(l[i], l[j]);
                maxEdge = max(maxEdge, l[k]);
                if ((l[i]+l[j]+l[k]) > 2*maxEdge) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
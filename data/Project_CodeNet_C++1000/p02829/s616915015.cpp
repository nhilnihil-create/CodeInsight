#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;

    int vis[4] = {};
    vis[a] = 1;
    vis[b] = 1;
    for (int i = 1; i <= 3; i++) {
        if(vis[i] == 0) {
            return cout << i, 0;
        }
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    int a, v, b, w, t;
    cin >> a >> v;
    cin >> b >> w;
    cin >> t;
    int dist = abs (a - b);
    int speed = v - w;
    if (speed <= 0) {
        cout << "NO\n";
        return 0;
    }
    if (1ll * t * speed >= dist)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

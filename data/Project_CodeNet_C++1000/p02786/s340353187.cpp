#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll f(ll now) {
    if (now==1) return 1;
    return 1 + 2*f(now/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll h; cin >> h;
    cout << f(h) << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
 
    ll dist = abs(a - b);
    ll dist2 = t *(v-w); 
    if (dist <= dist2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
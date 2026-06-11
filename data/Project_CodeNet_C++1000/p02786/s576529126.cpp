#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll depth = 0;
    ll h;
    cin >> h;
    while (h>0) {
        depth++;
        h/=2;
    }
    ll ans = 1;
    for (ll i=0; i<depth; i++) ans*=2;
    cout << ans-1;
    return 0;
}
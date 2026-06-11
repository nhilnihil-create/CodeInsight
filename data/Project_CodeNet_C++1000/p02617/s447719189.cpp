#include <iostream>
#include <algorithm>

using namespace std;

using ll =  long long;

int main() {
    ll n, u, v;
    cin >> n;
    ll ans = (n * (n+1) * (2*n+1) / 6 + n * (n+1) / 2) / 2;
    for(int i=0;i<n-1;++i) {
        cin >> u >> v;
        ans -= min(u, v) * (n - max(u, v) + 1);
    }
    cout << ans << endl;
}
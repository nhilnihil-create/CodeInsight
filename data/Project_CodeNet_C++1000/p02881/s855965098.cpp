#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = 1e15;

    for(ll i = 1; i*i <= N; i++) {
        //cout << i << endl;
        if(N%i == 0) {
            //cout << "#" << endl;
            ans = min(ans, i + N/i - 2);
        }
    }
    cout << ans << endl;

    return 0;
}
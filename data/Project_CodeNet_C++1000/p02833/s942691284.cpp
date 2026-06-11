#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N;
    cin >> N;
    if(N%2==1) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 0;
    for(ll i=10;i<(ll)1e18+7;i*=5){
        ans+=(N/i);
    }
    cout << ans << '\n';
}

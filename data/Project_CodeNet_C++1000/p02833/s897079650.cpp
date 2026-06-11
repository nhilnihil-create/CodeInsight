#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll d = 5, ans = 0;
    while (d <= n) {
        ll k = n / d;
        ans += k / 2;
        d *= 5;
    }
    cout << ans << endl;
}
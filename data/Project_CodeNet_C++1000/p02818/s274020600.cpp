#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, k; cin >> a >> b >> k;
    ll c = max(a-k, (ll)0), d = max(b - max(k-a, (ll)0), (ll)0);

    cout << c << " " << d << endl;
    return 0;
}
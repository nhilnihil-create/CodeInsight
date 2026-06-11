#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    auto res = 0;
    for (auto a = 1; a < n; a++) {
        res += (n - 1) / a;
    }

    cout << res << endl;
    return 0;
}

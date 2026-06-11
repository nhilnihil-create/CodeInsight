#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {

    int n;

    cin >> n;

    vector<ll> v(n);

    vector<ll> answer(n, 0);

    ll sum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];

        sum += i % 2 ? -v[i] : v[i];

    }

    cout << sum << " ";
    int prev = sum;

    for(int i = 0; i < n - 1; ++i) {
        cout << 2*v[i] - prev << " ";
        prev = 2 * v[i] - prev;
    }
    cout << endl;

    return 0;
}



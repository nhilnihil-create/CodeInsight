#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll ret = 0;
    for (int i = 1; i <= n; i++)ret += i * (n - i + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v)swap(u, v);
        ret -= u * (n - v + 1);
    }

    cout << ret << endl;
    return 0;
}
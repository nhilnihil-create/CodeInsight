#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, *a;
    cin >> n;
    a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll x = a[0];
    for (int i = 1; i < n; i++)
        x = x ^ a[i];

    for (int i = 0; i < n; i++)
        cout << (x ^ a[i]) << endl;

    return 0;
}
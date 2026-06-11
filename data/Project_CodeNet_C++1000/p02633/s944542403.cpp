#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define double long double
using namespace std;

ll n, p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    p = __gcd(n, (ll)360);
    p = n * 360 / p;
    cout << p / n;
    return 0;
}

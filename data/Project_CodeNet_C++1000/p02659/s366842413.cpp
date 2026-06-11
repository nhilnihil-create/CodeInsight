#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a;
    double b;
    cin >> a >> b;

    ll tmp = b * 100 + 0.5;

    ll ans = (a * tmp) / 100;

    cout << ans << endl;

    return 0;
}

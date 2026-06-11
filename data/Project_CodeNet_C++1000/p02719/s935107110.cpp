#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n, k; cin >> n >> k;
    ll mod = n % k;
    cout << min(mod, abs(k - mod)) << endl;
    return 0;
}
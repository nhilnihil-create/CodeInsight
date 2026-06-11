#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
int main() {
    ll h;
    int n;
    cin >> h >> n;
    ll damage = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        damage += a;
    }
    if (damage >= h) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}